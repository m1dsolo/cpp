#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

const int N = 1e3 + 10;

int n;
pair<int, int> arr[N];
int ps[N];

struct edge {
    int u;
    int v;
    double w;
} es[N * N + N];
int size;

int find(int a) {
    return a == ps[a] ? a : ps[a] = find(ps[a]);
}

void merge(int a, int b) {
    ps[find(b)] = find(a);
}

int main() {
    int m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
	scanf("%d %d", &arr[i].first, &arr[i].second);

    iota(ps + 1, ps + 1 + n, 1);

    for (int i = 1; i < n; i++) {
	for (int j = i + 1; j <= n; j++) {
	    double a = arr[i].first - arr[j].first, b = arr[i].second - arr[j].second;
	    es[size++] = {i, j, sqrt(a * a + b * b)};
	}
    }
    while (m--) {
	scanf("%d %d", &u, &v);
	es[size++] = {u, v, 0};
    }
    sort(es, es + size, [](const edge &e1, const edge &e2) {
	return e1.w < e2.w;
    });

    double rst = 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
	int p1 = find(es[i].u), p2 = find(es[i].v);
	if (p1 != p2) {
	    merge(p1, p2);
	    rst += es[i].w;
	    if (++sum == n - 1)
		break;
	}
    }
    printf("%.2lf\n", rst);

    return 0;
}
