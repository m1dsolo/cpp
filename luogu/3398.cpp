#include <iostream>
#include <list>

using namespace std;

const int N = 1e5 + 10;

list<int> adj[N];
int lg[N], ps[N][20], ds[N];

void dfs(int u, int p) {
    ps[u][0] = p, ds[u] = ds[p] + 1;
    for (int i = 1; i <= lg[ds[u]]; i++)
	ps[u][i] = ps[ps[u][i - 1]][i - 1];

    for (int v : adj[u])
	if (v != p) dfs(v, u);
}

int lca(int a, int b) {
    if (ds[a] < ds[b]) swap(a, b);
    while (ds[a] > ds[b])
	a = ps[a][lg[ds[a] - ds[b]] - 1];
    if (a == b) return a;
    for (int i = lg[ds[a]] - 1; i >= 0; i--) {
	if (ps[a][i] != ps[b][i])
	    a = ps[a][i], b = ps[b][i];
    }
    return ps[a][0];
}

int dis(int u, int v) {
    return ds[u] + ds[v] - 2 * ds[lca(u, v)];
}

int main() {
    int n, q, u, v;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n - 1; i++) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
	lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);

    dfs(1, 0);
    int u1, v1, u2, v2;
    while (q--) {
	scanf("%d %d %d %d", &u1, &v1, &u2, &v2);
	printf("%s\n", dis(u1, v1) + dis(u2, v2) >= dis(u1, u2) + dis(v1, v2) ? "Y" : "N");
    }

    return 0;
}
