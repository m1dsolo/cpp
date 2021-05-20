#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

struct edge {
    int from;
    int to;
    int len;
} edges[200010];

int n, m;
int parents[5010], sizes[5010], lens[5010];

int find(int a) {
    return a == parents[a] ? a : parents[a] = find(parents[a]);
}

int merge(int a, int b, int len) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 != p2) {
	parents[p2] = p1;
	sizes[p1] += sizes[p2];
	lens[p1] += lens[p2] + len;
	if (sizes[p1] == n)
	    return lens[p1];
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    iota(parents + 1, parents + n + 1, 1);
    fill(sizes + 1, sizes + n + 1, 1);
    for (int i = 0; i < m; i++)
	scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].len);

    sort(edges, edges + m, [](const edge &e1, const edge &e2) {
	return e1.len < e2.len;
    });

    int rst = -1;
    for (const edge &e : edges) {
	if (rst = merge(e.from, e.to, e.len))
	    break;
    }

    cout << rst << endl;

    return 0;
}
