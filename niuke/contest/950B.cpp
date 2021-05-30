// 贪心+(树状数组优化区间查询,arr用来优化单点查询,因为查询多修改少)(用线段树优化没想到怎么做，因为很难确定update区间)
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3e4 + 10;

struct q {
    int l;
    int r;
    int t;
} qs[5010];

int n, tree[N];
bool arr[N];

void update(int i) {
    for (; i <= n; i += i & -i)
	tree[i]++;
}

int query(int i) {
    int rst = 0;
    for (; i; i -= i & -i)
	rst += tree[i];
    return rst;
}

int main() {
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
	scanf("%d %d %d", &qs[i].l, &qs[i].r, &qs[i].t);
    sort(qs, qs + m, [](const q &q1, const q &q2) {
	return q1.r < q2.r;
    });

    int rst = 0;
    for (int i = 0; i < m; i++) {
	int a = query(qs[i].r) - query(qs[i].l - 1), p = qs[i].r;
	while (a < qs[i].t) {
	    if (!arr[p]) {
		arr[p] = 1;
		update(p);
		a++;
		rst++;
	    }
	    p--;
	}
    }

    printf("%d\n", rst);

    return 0;
}
