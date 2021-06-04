#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int N = 1e4 + 10;

int dfn[N], low[N], stack[N], top, cnt, bl[N], outd[N];
bool instack[N];
vector<int> adj[N];

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
	    instack[stack[top]] = false;
	} while (u != stack[top--]);
    }
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    while (m--) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
    }

    for (int i = 1; i <= n; i++)
	if (!dfn[i]) tarjan(i);

    unordered_set<int> set;
    for (int u = 1; u <= n; u++) {
	for (int v : adj[u]) {
	    if (bl[u] != bl[v] && !set.count(bl[u] * 2e4 + bl[v])) {
		set.insert(bl[u] * 2e4 + bl[v]);
		outd[bl[u]]++;
	    }
	}
    }

    int a = 0, rst = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
	if (bl[i] == i && !outd[i]) {
	    if (a) {
		flag = true;
		break;
	    }
	    a = i;
	}
    }
    if (!flag) {
	for (int i = 1; i <= n; i++)
	    if (bl[i] == a) rst++;
    }

    printf("%d\n", rst);

    return 0;
}
