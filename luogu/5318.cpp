#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
bool visited[N];

int n, m;

void dfs(int a) {
    printf("%d ", a);
    visited[a] = true;
    for (int b : adj[a]) {
	if (!visited[b])
	    dfs(b);
    }
}

void bfs(int a) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.emplace(a);
    visited[a] = true;
    while (int size = q.size()) {
	while (size--) {
	    int a = q.front(); q.pop();
	    printf("%d ", a);
	    for (int b : adj[a]) {
		if (!visited[b]) {
		    q.emplace(b);
		    visited[b] = true;
		}
	    }
	}
    }
}

int main() {
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
	scanf("%d %d", &a, &b);
	adj[a].emplace_back(b);
    }
    for (int i = 1; i <= n; i++) {
	sort(adj[i].begin(), adj[i].end());
    }

    dfs(1);
    printf("\n");
    bfs(1);
    printf("\n");

    return 0;
}
