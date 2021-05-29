#include <iostream>
#include <list>

using namespace std;

const int N = 5e5 + 10;

int n;
list<int> adj[N]; 
int ps[N][25], ds[N], lg[N];

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
    int m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
	lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);

    dfs(1, 0);

    int x, y, z;
    while (m--) {
	scanf("%d %d %d", &x, &y, &z);
	int a = lca(x, y), b = lca(x, z), c = lca(y, z);
	int p = ds[a] == ds[b] ? c : (ds[a] > ds[b] ? a : b);
	printf("%d %d\n", p, dis(x, p) + dis(y, p) + dis(z, p));
    }

    return 0;
}
