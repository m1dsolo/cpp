#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

const int N = 5e3 + 10;

list<int> adj[N];

int dfn[N], low[N], stack[N], bl[N], size[N], arr[N], top, cnt, max_size, max_index;
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
	    if (u != stack[top]) {
		if ((size[u] += size[stack[top]]) > max_size) {
		    max_size = size[u];
		    max_index = u;
		}
	    }
	    instack[stack[top]] = false;
	} while (u != stack[top--]);
    }
}

int main() {
    int n, m, u, v, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &u, &v, &t);
	adj[u].emplace_back(v);
	if (t == 2)
	    adj[v].emplace_back(u);
    }
    fill(size + 1, size + 1 + n, 1);

    for (int i = 1; i <= n; i++)
	if (!dfn[i]) tarjan(i);

    int num = 0;
    for (int i = 1; i <= n; i++) {
	if (bl[i] == max_index)
	    arr[num++] = i;
    }

    printf("%d\n", max_size);
    for (int i = 0; i < max_size; i++)
	printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
