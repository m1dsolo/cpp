#include <iostream>

using namespace std;

const int N = 2e5 + 10;
int n, arr[N], nodes[N << 2];

void build(int p = 1, int cl = 1, int cr = n) {
    if (cl == cr) { nodes[p] = arr[cl]; return; }
    int mid = (cl + cr) >> 1;
    build(p << 1, cl, mid);
    build(p << 1 | 1, mid + 1, cr);
    nodes[p] = max(nodes[p << 1], nodes[p << 1 | 1]);
}

int query(int l, int r, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) return nodes[p];
    int mid = (cl + cr) >> 1, rst = 0;
    if (mid >= l) rst = max(rst, query(l, r, p << 1, cl, mid));
    if (mid < r) rst = max(rst, query(l, r, p << 1 | 1, mid + 1, cr));
    return rst;
}

int main() {
    int m, l, r;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);
    build();

    while (m--) {
	scanf("%d %d", &l, &r);
	printf("%d\n", query(l, r));
    }

    return 0;
}
