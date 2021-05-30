#include <iostream>
#include <list>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
using P = pair<int, int>;

struct way {
    int v;
    int w;
    int c;
    way(int v, int w, int c) : v(v), w(w), c(c) {}
};

const int N = 510;

int dis[N], rst_cost = 2e9;
list<way> adj[N];
vector<pair<int, int>> pre[N];	// v, cost
vector<int> path, rst_path;

int s;
bool visited[N];
void dfs(int u, int cost) {
    if (cost > rst_cost) return;
    path.emplace_back(u);
    visited[u] = true;
    if (u == s) {
	rst_cost = cost;
	rst_path = path;
    }
    else for (P p : pre[u]) {
	int v = p.first, c = p.second;
	if (!visited[p.first])
	    dfs(v, cost + c);
    }
    visited[u] = false;
    path.pop_back();
}

int main() {
    int n, m, d;
    scanf("%d %d %d %d", &n, &m, &s, &d);
    int u, v, w, c;
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d %d", &u, &v, &w, &c);	
	adj[u].push_back({v, w, c});
	adj[v].push_back({u, w, c});
    }

    memset(dis, 127, sizeof(int) * n); dis[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, s});

    while (int size = q.size()) {
	while (size--) {
	    int val = q.top().first, u = q.top().second; q.pop();
	    if (val != dis[u]) continue;
	    for (way &w : adj[u]) {
		if (val + w.w < dis[w.v]) {
		    q.push({dis[w.v] = val + w.w, w.v});
		    pre[w.v].clear();
		    pre[w.v].push_back({u, w.c});
		}
		else if (val + w.w == dis[w.v])
		    pre[w.v].push_back({u, w.c});
	    }
	}
    }

    dfs(d, 0);

    for (int i = rst_path.size() - 1; i >= 0; i--)
	printf("%d ", rst_path[i]);
    printf("%d %d\n", dis[d], rst_cost);

    return 0;
}
