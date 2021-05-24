// WA why???
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 1e5 + 10;

struct st {
    int val;
    char c;
    int rank;
} sts[N];

int n, orders[N];

struct node {
    int sum = 0;
    int max = 0;
    node() {}
    node(int a) : sum(a), max(a) {}
    node(int sum, int max) : sum(sum), max(max) {}
} nodes[N << 2];

struct tag {
    int add = 0;
    tag() {}
    tag(int add) : add(add) {}
} tags[N << 2];

inline node nn(const node &n1, const node &n2) {return {n1.sum + n2.sum, max(n1.max, n2.max)};}
inline node nt(const node &n, const tag &t, int len) {return {n.sum + t.add * len, n.max + t.add};}
inline tag tt(const tag &t1, const tag &t2) {return {t1.add + t2.add};}

void push_down(int p, int len) {
    nodes[p << 1] = nt(nodes[p << 1], tags[p], len - (len >> 1));
    nodes[p << 1 | 1] = nt(nodes[p << 1 | 1], tags[p], len >> 1);
    tags[p << 1] = tt(tags[p << 1], tags[p]);
    tags[p << 1 | 1] = tt(tags[p << 1 | 1], tags[p]);
    tags[p] = tags[0];
}

void update(int l, int r, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) {nodes[p] = nt(nodes[p], {1}, cr - cl + 1); tags[p] = tt(tags[p], {1}); return;}
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1;
    if (mid >= l) update(l, r, p << 1, cl, mid);
    if (mid < r) update(l, r, p << 1 | 1, mid + 1, cr);
    nodes[p] = nn(nodes[p << 1], nodes[p << 1 | 1]);
}

node query(int l, int r, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) return nodes[p];
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1;
    node rst;
    if (mid >= l) rst = nn(rst, query(l, r, p << 1, cl, mid));
    if (mid < r) rst = nn(rst, query(l, r, p << 1 | 1, mid + 1, cr));
    return rst;
}

int main() {
    int m, a;
    scanf("%d", &m);
    char c;
    for (int i = 0; i < m; i++)
	scanf("%d %s", &sts[i].val, &sts[i].c);

    iota(orders, orders + m, 0);
    sort(orders, orders + m, [&](int i, int j) {
	return sts[i].val < sts[j].val;
    });
    sts[orders[0]].rank = 2;	// 留前
    for (int i = 1; i < m; i++)
	sts[orders[i]].rank = sts[orders[i - 1]].rank + (sts[orders[i]].val != sts[orders[i - 1]].val);
    n = sts[orders[m - 1]].rank + 1;// 留后

    for (int i = 0; i < m; i++) {
	switch (sts[i].c) {
	    case '+': update(1, sts[i].rank - 1); break;
	    case '.': update(sts[i].rank, sts[i].rank); break;
	    case '-': update(sts[i].rank + 1, n); break;
	}
    }

    for (int i = 1; i <= n; i++)
	cout << query(i, i).sum << " " << query(i, i).max << endl;

    printf("%d\n", query(1, n).max);

    return 0;
}
