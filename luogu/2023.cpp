#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, p, arr[N];
ll tree[N << 2];

struct tag {
    ll add = 0;
    ll mul = 1;
    tag() {}
    tag(ll add, ll mul) : add(add), mul(mul) {}
} tags[N << 2];

inline ll add(ll a, ll b) { return (a + b) % p; }
inline ll mul(ll a, ll b) { return (a * b) % p; }
inline void addt(ll &a, const tag &t, int len) { a = add(mul(a, t.mul), mul(t.add, len)); }
inline void addtt(tag &t1, const tag &t2) { t1.add = add(mul(t1.add, t2.mul), t2.add), t1.mul = mul(t1.mul, t2.mul); }

void push_down(int p, int len) {
    addt(tree[p << 1], tags[p], len - (len >> 1));
    addt(tree[p << 1 | 1], tags[p], len >> 1);
    addtt(tags[p << 1], tags[p]);
    addtt(tags[p << 1 | 1], tags[p]);
    tags[p] = tags[0];
}

void build(int p = 1, int cl = 1, int cr = n) {
    if (cl == cr) {tree[p] = arr[cl]; return;}
    int mid = (cl + cr) >> 1;
    build(p << 1, cl, mid);
    build(p << 1 | 1, mid + 1, cr);
    tree[p] = add(tree[p << 1], tree[p << 1 | 1]);
}

void update(int l, int r, const tag &t, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) {addt(tree[p], t, cr - cl + 1); addtt(tags[p], t); return;}
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1;
    if (mid >= l) update(l, r, t, p << 1, cl, mid);
    if (mid < r) update(l, r, t, p << 1 | 1, mid + 1, cr);
    tree[p] = add(tree[p << 1], tree[p << 1 | 1]);
}

ll query(int l, int r, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) return tree[p];
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1;
    ll rst = 0;
    if (mid >= l) rst = add(rst, query(l, r, p << 1, cl, mid));
    if (mid < r) rst = add(rst, query(l, r, p << 1 | 1, mid + 1, cr));
    return rst;
}

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);
    build();
    int m, a, l ,r, d;
    scanf("%d", &m);
    while (m--) {
	scanf("%d %d %d", &a, &l, &r);
	if (a == 3)
	    printf("%lld\n", query(l, r));
	else {
	    scanf("%d", &d);
	    if (a == 1) update(l, r, {.add = 0, .mul = d});
	    else update(l, r, {.add = d, .mul = 1});
	}
    }

    return 0;
}
