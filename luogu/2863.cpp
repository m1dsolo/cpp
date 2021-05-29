#include <iostream>
#include <list>

using namespace std;

const int N = 2e4 + 10;

int n, dfn[N], low[N], stack[N], idx, top, rst;
list<int> adj[N];
bool instack[N];

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
	int cnt = 0;
	do {
	    cnt++;
	    instack[stack[top]] = false;
	} while (u != stack[top--]);
	if (cnt > 1) rst++;
    }
}

int main() {
    int m, u, v;
    scanf("%d %d", &n, &m);
    while (m--) {
	scanf("%d %d", &u, &v);	
	adj[u].emplace_back(v);
    }

    for (int i = 1; i <= n; i++)
	if (!dfn[i]) tarjan(i);

    printf("%d\n", rst);

    return 0;
}
