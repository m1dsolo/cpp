#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
using P = pair<int, int>;

const int N = 160;

int dfn[N], low[N], idx, size;
list<int> adj[N];
P rst[N];

void tarjan(int u, int p) {
    dfn[u] = low[u] = ++idx;
    for (int v : adj[u]) {
	if (!dfn[v]) {
	    tarjan(v, u);
	    low[u] = min(low[u], low[v]);
	    if (low[v] > dfn[u]) {
		if (u > v) rst[size] = {v, u};
		else rst[size] = {u, v};
		size++;
	    }
	}
	if (v != p)	// 注意判断是必须的，否则答案会少
	    low[u] = min(low[u], dfn[v]);
    }
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    while (m--) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
	if (!dfn[i]) tarjan(i, 0);
    sort(rst, rst + size);

    for (int i = 0; i < size; i++)
	printf("%d %d\n", rst[i].first, rst[i].second);

    return 0;
}
