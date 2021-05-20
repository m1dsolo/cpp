#include <iostream>
#include <list>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

list<int> adj[N];
int ind[N], rst[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int u, v;
    while (m--) {
	scanf("%d %d", &u, &v);
	ind[v]++;
	adj[u].emplace_back(v);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
	if (!ind[i]) {
	    rst[i] = 1;
	    q.emplace(i);
	}
    }

    int level = 2;
    while (int size = q.size()) {
	while (size--) {
	    int u = q.front(); q.pop();
	    for (int v : adj[u]) {
		if (!--ind[v]) {
		    rst[v] = level;
		    q.emplace(v);
		}
	    }
	}
	level++;
    }

    for (int i = 1; i <= n; i++)
	printf("%d\n", rst[i]);

    return 0;
}
