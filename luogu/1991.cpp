#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

const int N = 1e6 + 10;

struct edge {
    int u;
    int v;
    double w;
} es[N];

int cnt;

struct points {
    int x;
    int y;
} pts[N];

int ps[N];

int find(int a) {
    return a == ps[a] ? a : ps[a] = find(ps[a]);
}

void merge(int a, int b) {
    ps[find(b)] = ps[find(a)];
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    if (!k) k++;
    for (int i = 1; i <= n; i++) {
	scanf("%d %d", &pts[i].x, &pts[i].y);
	for (int j = 1; j < i; j++)
	    es[cnt++] = {j, i, sqrt(pow(pts[j].x - pts[i].x, 2) + pow(pts[j].y - pts[i].y, 2))};
    }
    sort(es, es + cnt, [](const edge &e1, const edge &e2) {
	return e1.w < e2.w;
    });

    iota(ps + 1, ps + 1 + n, 1);
    int sum = 0, i;
    for (i = 0; i < cnt; i++) {
	int p1 = find(es[i].u), p2 = find(es[i].v);
	if (p1 != p2) {
	    merge(p1, p2);
	    if (++sum == n - k)
		break;
	}
    }

    printf("%.2lf\n", es[i].w);

    return 0;
}
