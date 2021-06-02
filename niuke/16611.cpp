#include <iostream>
#include <list>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, maxs[N], mins[N], dfn[N], low[N], stack[N], bl[N], ind[N], minn[N], dp[N], top, cnt;	// minn和dp是用来dp的，minn不能改为mins
bool instack[N];

list<int> adj[N], adj2[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
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
	    maxs[u] = max(maxs[u], maxs[stack[top]]);
	    mins[u] = min(mins[u], mins[stack[top]]);
	    instack[stack[top]] = false;
	} while (u != stack[top--]);
    }
}

void topo() {
    queue<int> q;
    for (int u = 1; u <= n; u++) {
	if (bl[u] == u && !ind[u])
	    q.emplace(u);
    }

    while (int size = q.size()) {
	while (size--) {
	    int u = q.front(); q.pop();
	    for (int v : adj2[u]) {
		minn[v] = min(minn[v], mins[u]);
		dp[v] = max(max(dp[u], dp[v]), maxs[v] - minn[v]);	// 注意
		if (!--ind[v])
		    q.emplace(v);
	    }
	}
    }
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
	scanf("%d", &maxs[i]);
	mins[i] = maxs[i];
    }
    int u, v, w;
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &u, &v, &w);
	adj[u].emplace_back(v);
	if (w == 2)
	    adj[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
	if (!dfn[i]) tarjan(i);

    for (int u = 1; u <= n; u++) {
	for (int v : adj[u]) {
	    if (bl[u] != bl[v]) {
		adj2[bl[u]].emplace_back(bl[v]);
		ind[bl[v]]++;
	    }
	}
    }

    for (int i = 1; i <= n; i++) {
	minn[i] = mins[i];
	dp[i] = maxs[i] - mins[i];
    }

    topo();
    printf("%d\n", dp[n]);

    return 0;
}
