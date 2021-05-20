#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, arr[N];
ll tree[N << 2], mark[N << 2];

void push_down(int p, int len) {
    tree[p << 1] += mark[p] * (len - (len >> 1));
    mark[p << 1] += mark[p];
    tree[p << 1 | 1] += mark[p] * (len >> 1);
    mark[p << 1 | 1] += mark[p];
    mark[p] = 0;
}

void build(int p = 1, int cl = 1, int cr = n) {
    if (cl == cr) {tree[p] = arr[cl]; return;}
    int mid = (cl + cr) >> 1;
    build(p << 1, cl, mid);
    build(p << 1 | 1, mid + 1, cr);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

void update(int l, int r, int d, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) {tree[p] += d * (cr - cl + 1); mark[p] += d; return;}
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1;
    if (mid >= l) update(l, r, d, p << 1, cl, mid);
    if (mid < r) update(l, r, d, p << 1 | 1, mid + 1, cr);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

ll query(int l, int r, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) return tree[p];
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1;
    ll rst = 0;
    if (mid >= l) rst += query(l, r, p << 1, cl, mid);
    if (mid < r) rst += query(l, r, p << 1 | 1, mid + 1, cr);
    return rst;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);
    build();

    int a, l, r, d;
    while (m--) {
	scanf("%d %d %d", &a, &l, &r);
	if (a == 1)
	    scanf("%d", &d), update(l, r, d);
	else
	    printf("%lld\n", query(l, r));
    }

    return 0;
}
