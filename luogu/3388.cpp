// 注意是无向图，而求强连通分量是有向图
#include <iostream>
#include <list>

using namespace std;

const int N = 2e4 + 10;

int n, dfn[N], low[N], idx;
list<int> adj[N];
bool cut[N];

void tarjan(int u, int root) {
    dfn[u] = low[u] = ++idx;
    int child = 0;
    for (int v : adj[u]) {
	if (!dfn[v]) {
	    tarjan(v, root);
	    low[u] = min(low[u], low[v]);
	    child++;
	    if (u == root && child >= 2 || u != root && low[v] >= dfn[u])
		cut[u] = true;
	}
	low[u] = min(low[u], dfn[v]);
    }
}

int main() {
    int m, u, v;
    scanf("%d %d", &n, &m);
    while (m--) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
	if (!dfn[i]) tarjan(i, i);

    int rst = 0;
    for (int i = 1; i <= n; i++)
	if (cut[i]) rst++;
    printf("%d\n", rst);
    for (int i = 1; i <= n; i++)
	if (cut[i]) printf("%d ", i);
    printf("\n");

    return 0;
}
