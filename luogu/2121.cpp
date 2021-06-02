#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 1e5 + 10;

struct edge {
    int u;
    int v;
    int w;
} es[N];

int ps[N];

int find(int a) {
    return a == ps[a] ? a : ps[a] = find(ps[a]);
}

void merge(int a, int b) {
    ps[find(b)] = find(a);
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
	scanf("%d %d %d", &es[i].u, &es[i].v, &es[i].w);
    sort(es, es + m, [](const edge &e1, const edge &e2) {
	return e1.w > e2.w;
    });

    int cnt = 0, rst = 0;
    iota(ps + 1, ps + 1 + n, 1);
    for (int i = 0; i < m; i++) {
	int p1 = find(es[i].u), p2 = find(es[i].v);
	if (p1 != p2) {
	    merge(p1, p2);
	    rst += es[i].w;
	    if (++cnt == k)
		break;
	}
    }

    printf("%d\n", rst);

    return 0;
}
