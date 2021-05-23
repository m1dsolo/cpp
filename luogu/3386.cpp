// O(V * E)
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

const int N = 510;

list<int> adj[N];
bool visited[N];
int match[N];

int l, r;
bool dfs(int u) {
    for (int v : adj[u]) {
	if (!visited[v]) {
	    visited[v] = true;
	    if (!match[v] || dfs(match[v])) {
		match[v] = u;
		return true;
	    }
	}
    }
    return false;
}

int hagarian() {
    int rst = 0;
    for (int i = 1; i <= l; i++) {
	memset(visited + 1, false, r);
	if (dfs(i)) rst++;
    }
    return rst;
}
int main() {
    int m, u, v;
    scanf("%d %d %d", &l, &r, &m);
    while (m--) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
    }

    printf("%d\n", hagarian());

    return 0;
}
