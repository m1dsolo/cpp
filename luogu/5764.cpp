#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
using P = pair<int, int>;

const int N = 5e4 + 10, INT_MAX = 0x3f3f3f3f;

struct edge {
    int v;
    int w;
};

int arr[6] = {1}, dis[6][N];
vector<edge> adj[N];

void dij(int s, int *dis) {
    dis[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, s});
    while (int size = q.size()) {
	while (size--) {
	    int val = q.top().first, u = q.top().second; q.pop();
	    if (val != dis[u]) continue;
	    for (edge &e : adj[u]) {
		if (dis[u] + e.w < dis[e.v]) {
		    dis[e.v] = dis[u] + e.w;
		    q.push({dis[e.v], e.v});
		}
	    }
	}
    }
}

int rst = 2e9;
bool visited[6];
void dfs(int u, int cnt, int val) {
    visited[u] = true;
    if (++cnt == 6)
	rst = min(rst, val);
    else {
	for (int v = 0; v < 6; v++) {
	    if (!visited[v] && dis[u][arr[v]] != INT_MAX)
		dfs(v, cnt, val + dis[u][arr[v]]);
	}
    }
    visited[u] = false;
}

int main() {
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= 5; i++)
	scanf("%d", &arr[i]);
    while (m--) {
	scanf("%d %d %d", &u, &v, &w);
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
    }

    memset(dis, 0x3f, sizeof(dis));
    dij(1, dis[0]);
    for (int i = 1; i <= 5; i++)
	dij(arr[i], dis[i]);

    dfs(0, 0, 0);

    printf("%d\n", rst);

    return 0;
}
