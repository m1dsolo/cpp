#include <iostream>
#include <list>
#include <queue>

using namespace std;

const int N = 1e4 + 10;

int n;
int wts[N], bl[N], dfn[N], low[N], stack[N], idx, top;
bool instack[N];
list<int> adj[N], adj2[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    stack[++top] = u;
    instack[u] = true;
    for (int v : adj[u]) {
	if (!dfn[v]) {
	    tarjan(v);
	    low[u] = min(low[u], low[v]);
	}
	else if (instack[v])
	    low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
	do {
	    bl[stack[top]] = u;
	    if (u != stack[top])
		wts[u] += wts[stack[top]];
	    instack[stack[top]] = false;
	} while(u != stack[top--]);
    }
}

int dp[N], ind[N], rst;
void topo() {
    queue<int> q;
    for (int u = 1; u <= n; u++) {
	if (bl[u] == u && !ind[u]) {
	    q.emplace(u);
	    rst = max(rst, dp[u] = wts[u]);	    // 别忘了更新rst!
	}
    }
    while (int size = q.size()) {
	while (size--) {
	    int u = q.front(); q.pop();
	    for (int v : adj2[u]) {
		rst = max(rst , dp[v] = max(dp[v], dp[u] + wts[v]));
		if (!--ind[v])
		    q.emplace(v);
	    }
	}
    }
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
	scanf("%d", &wts[i]);

    int u, v;
    for (int i = 1; i <= m; i++) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
    }

    for (int i = 1; i <= n; i++)
	if (!dfn[i]) tarjan(i);

    // unordered_set<pair<int, int>, hash_pair> set;	    // 可以防止边重复
    for (int u = 1; u <= n; u++) {
	for (int v : adj[u]) {
	    if (bl[u] != bl[v]) {
		adj2[bl[u]].emplace_back(bl[v]);
		ind[bl[v]]++;
	    }
	}
    }
    topo();

    printf("%d\n", rst);

    return 0;
}
