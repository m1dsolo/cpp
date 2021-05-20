// https://www.luogu.com.cn/blog/user15019/solution-p3373
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int arr[N], n, mod;
ll tree[N << 2];

struct tag {
    ll add = 0; 
    ll mul = 1;
    tag() {}
    tag(ll add, ll mul) : add(add), mul(mul) {}
} tags[N << 2];

inline ll add(ll a, ll b) { return (a + b) % mod; }
inline ll mul(ll a, ll b) { return (a * b) % mod; }
inline ll addt(ll a, tag t, ll len) { return add(mul(a, t.mul), mul(t.add, len)); };
inline tag addtt(tag t1, tag t2) { return {.add = add(mul(t1.add, t2.mul), t2.add), .mul = mul(t1.mul, t2.mul)}; }

// 先乘后加，同时add标记要先乘mul标记
// 叶子节点会不会push_down会不会造成需要8倍空间的情况?
void push_down(int p, int len) {
    //if (len == 1) return;
    tree[p << 1] = addt(tree[p << 1], tags[p], len - (len >> 1));
    tree[p << 1 | 1] = addt(tree[p << 1 | 1], tags[p], len >> 1);
    tags[p << 1] = addtt(tags[p << 1], tags[p]);
    tags[p << 1 | 1] = addtt(tags[p << 1 | 1], tags[p]);

    tags[p] = tags[0];
}

void build(int p = 1, int cl = 1, int cr = n) {
    if (cl == cr) {tree[p] = arr[cl]; return;}
    int mid = (cl + cr) >> 1;
    build(p << 1, cl, mid);
    build(p << 1 | 1, mid + 1, cr);
    tree[p] = add(tree[p << 1], tree[p << 1 | 1]);
}

void update(int l, int r, tag t, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) {tree[p] = addt(tree[p], t, cr - cl + 1), tags[p] = addtt(tags[p], t); return;}
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1;
    if (mid >= l) update(l, r, t, p << 1, cl, mid);
    if (mid < r) update(l, r, t, p << 1 | 1, mid + 1, cr);
    tree[p] = add(tree[p << 1], tree[p << 1 | 1]);
}

ll query(int l, int r, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) return tree[p];
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1, rst = 0;
    if (mid >= l) rst = add(rst, query(l, r, p << 1, cl, mid));
    if (mid < r) rst = add(rst, query(l, r, p << 1 | 1, mid + 1, cr));
    return rst;
}

int main() {
    int m;
    //scanf("%d %d %d", &n, &m, &mod);
    scanf("%d %d", &n, &mod);
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);
    build();
    scanf("%d", &m);
    while (m--) {
	int o, l, r, d;
	scanf("%d %d %d", &o, &l, &r);
	if (o == 3)
	    printf("%lld\n", query(l, r));
	else {
	    scanf("%d", &d);
	    if (o == 1) update(l, r, {.add = 0, .mul = d});
	    else update(l, r, {.add = d, .mul = 1});
	}
    }

    return 0;
}
