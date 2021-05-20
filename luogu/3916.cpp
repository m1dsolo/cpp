#include <iostream>
#include <list>

using namespace std;

int n, m;

list<int> adj[100010];
bool visited[100010];
int rst[100010];

void dfs(int u, int val) {
    visited[u] = true;
    rst[u] = val;
    for (int v : adj[u]) {
	if (!visited[v])
	    dfs(v, val);
    }
}

int main() {
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
	scanf("%d %d", &a, &b);
	adj[b].emplace_back(a);
    }

    for (int i = n; i >= 1; i--) {
	if (!visited[i])
	    dfs(i, i);
    }

    for (int i = 1; i <= n; i++)
	printf("%d ", rst[i]);
    printf("\n");

    return 0;
}
