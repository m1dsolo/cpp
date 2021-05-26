// https://www.luogu.com.cn/blog/morslin/solution-p3379
#include <iostream>
#include <list>

using namespace std;

const int N = 5e5 + 10;

list<int> adj[N];
int lg[N];
int ps[N][20], depth[N];

void dfs(int u, int p) {
    ps[u][0] = p; depth[u] = depth[p] + 1;
    for (int i = 1; i <= lg[depth[u]]; i++)
	ps[u][i] = ps[ps[u][i - 1]][i - 1];

    for (int v : adj[u]) {
	if (v != p)
	    dfs(v, u);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b])
	swap(a, b);
    while (depth[a] > depth[b])
	a = ps[a][lg[depth[a] - depth[b]] - 1];
    if (a == b) return a;

    for (int i = lg[depth[a]] - 1; i >= 0; i--) {
	if (ps[a][i] != ps[b][i])
	    a = ps[a][i], b = ps[b][i];
    }

    return ps[a][0];
}

int main() {
    int n, m, s, u, v;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n - 1; i++) {
	scanf("%d %d", &u, &v);	
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
	lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    dfs(s, 0);

    int a, b;
    while (m--) {
	scanf("%d %d", &a, &b);
	printf("%d\n", lca(a, b));
    }

    return 0;
}
