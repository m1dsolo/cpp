#include <iostream>
#include <list>
#include <unordered_set>
#include <algorithm>

using namespace std;
using P = pair<int, int>;

const int N = 1e4 + 10;

list<int> adj[N];

int dfn[N], low[N], stack[N], bl[N], size[N], outd[N], top, cnt;
bool instack[N];

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
	    if (u != stack[top])
		size[u] += size[stack[top]];
	    instack[u] = false;
	} while (u != stack[top--]);
    }
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
    }

    fill(size + 1, size + 1 + n, 1);
    for (int i = 1; i <= n; i++)
	if (!dfn[i]) tarjan(i);

    unordered_set<int> set;
    for (int u = 1; u <= n; u++) {
	for (int v : adj[u]) {
	    int key = bl[u] * 2e4 + bl[v];
	    if (bl[u] != bl[v] && !set.count(key)) {
		set.insert(key);
		outd[bl[u]]++;
	    }
	}
    }

    int rst = 0;
    for (int i = 1; i <= n; i++) {
	if (i == bl[i] && !outd[i]) {
	    if (rst) {
		rst = 0;
		break;
	    }
	    rst = size[i];
	}
    }

    printf("%d\n", rst);

    return 0;
}
