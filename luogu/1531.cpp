#include <iostream>

using namespace std;

const int N = 2e5 + 10;
int n, arr[N], tree[N << 2], tags[N << 2];

void push_down(int p) {
    tree[p << 1] = max(tree[p << 1], tags[p]);
    tree[p << 1 | 1] = max(tree[p << 1 | 1], tags[p]);
    tags[p << 1] = max(tags[p << 1], tags[p]);
    tags[p << 1 | 1] = max(tags[p << 1 | 1], tags[p]);

    tags[p] = 0;
}

void build(int p = 1, int cl = 1, int cr = n) {
    if (cl == cr) {tree[p] = arr[cl]; return;}
    int mid = (cl + cr) >> 1;
    build(p << 1, cl, mid);
    build(p << 1 | 1, mid + 1, cr);
    tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}

void update(int l, int r, int d, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) {tree[p] = max(tree[p], d), tags[p] = max(tags[p], d); return;}
    push_down(p);
    int mid = (cl + cr) >> 1;
    if (mid >= l) update(l, r, d, p << 1, cl, mid);
    if (mid < r) update(l, r, d, p << 1 | 1, mid + 1, cr);
    tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}

int query(int l, int r, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) return tree[p];
    push_down(p);
    int mid = (cl + cr) >> 1, rst = 0;
    if (mid >= l) rst = max(rst, query(l, r, p << 1, cl, mid));
    if (mid < r) rst = max(rst, query(l, r, p << 1 | 1, mid + 1, cr));
    return rst;
}

int main() {
    ios::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
	cin >> arr[i];
    build();
    int a, b;
    char c;
    while (m--) {
	cin >> c >> a >> b;
	if (c == 'Q')
	    printf("%d\n", query(a, b));
	else
	    update(a, a, b);
    }

    return 0;
}
