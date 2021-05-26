#include <iostream>
#include <climits>

using namespace std;

const int N = 2e5;

int n;
int arr[N];

struct node {
    int sum = 0;
    int max = 0;
    int min = INT_MAX;
    node() {}
    node(int a) : sum(a), max(a), min(a) {}
    node(int sum, int max, int min) : sum(sum), max(max), min(min) {}
} nodes[N << 2];

struct tag {
    int add = 0;
    tag() {}
    tag(int add) : add(add) {}
} tags[N << 2];

inline node nn(const node &n1, const node &n2) { return { n1.sum + n2.sum, max(n1.max, n2.max), min(n1.min, n2.min) }; }
inline node nt(const node &n, const tag &t, int len) { return { n.sum + t.add * len, n.max + t.add, n.min + t.add }; }
inline tag tt(const tag &t1, const tag &t2) { return {t1.add + t2.add}; }

void build(int p = 1, int cl = 1, int cr = n) {
    if (cl == cr) { nodes[p] = {arr[cl]}; return; }
    int mid = (cl + cr) >> 1;
    build(p << 1, cl, mid);
    build(p << 1 | 1, mid + 1, cr);
    nodes[p] = nn(nodes[p << 1], nodes[p << 1 | 1]);
}

void push_down(int p, int len) {
    nodes[p << 1] = nt(nodes[p << 1], tags[p], len - (len >> 1));
    nodes[p << 1 | 1] = nt(nodes[p << 1 | 1], tags[p], len >> 1);
    tags[p << 1] = tt(tags[p << 1], tags[p]);
    tags[p << 1 | 1] = tt(tags[p << 1 | 1], tags[p]);
    tags[p] = tags[0];
}

void update(int l, int r, const tag &t, int p = 1, int cl = 1, int cr = n) {
    if (cl >= l && cr <= r) { nodes[p] = nt(nodes[p], t, cr - cl + 1), tags[p] = tt(tags[p], t); return; }
    push_down(p, cr - cl + 1);
    int mid = (cl + cr) >> 1;
    if (mid >= l) update(l, r, t, p << 1, cl, mid);
    if (mid < r) update(l, r, t, p << 1 | 1, mid + 1, cr);
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
    int q;
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);
    build();

    int l, r;
    while (q--) {
	scanf("%d %d", &l, &r);
	node rst = query(l, r);
	printf("%d\n", rst.max - rst.min);
    }

    return 0;
}
