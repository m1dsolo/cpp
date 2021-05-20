// https://zhuanlan.zhihu.com/p/106118909
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 100;
int arr[N], tree[N << 2], mark[N << 2], n;

void push_down(int p, int len) {
    tree[p << 1] += mark[p] * (len - (len >> 1));
    tree[p << 1 | 1] += mark[p] * (len >> 1);
    mark[p << 1] += mark[p];
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
    if (cl >= l && cr <= r) {tree[p] += d * (cr - cl + 1), mark[p] += d; return;}
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1;
    if (mid >= l) update(l, r, d, p << 1, cl, mid);
    if (mid < r) update(l, r, d, p << 1 | 1, mid + 1, cr);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

int query(int l, int r, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) return tree[p];
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1, rst = 0;
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
    while (m--) {
	int o, l, r, d;
	scanf("%d %d %d", &o, &l, &r);
	if (o == 1)
	    scanf("%d", &d), update(l, r, d);
	else
	    printf("%d\n", query(l, r));
    }

    return 0;
}
