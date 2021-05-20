#include <iostream>
#include <list>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
using P = pair<int, int>;

const int N = 510;

int c, n, d, m;
int arr[N], dis[N];
list<P> adj[N];
bool visited[N];
vector<int> pre[N], path, rst_path;
int rst_send = 1000000, rst_take = 1000000;

void dfs(int v) {
    path.emplace_back(v);
    if (!v) {
	int send = 0, take = 0;
	for (int i = 0; i < path.size() - 1; i++) {
	    send = max(0, send + c / 2 - arr[path[i]]);
	    take += arr[path[i]];
	}
	take += send - (path.size() - 1) * (c / 2);
	if (send < rst_send || (send == rst_send && take < rst_take)) {
	    rst_send = send;
	    rst_take = take;
	    rst_path = path;
	}
    }
    else {
	for (int u : pre[v])
	    dfs(u);
    }
    path.pop_back();
}

int main() {
    scanf("%d %d %d %d", &c, &n, &d, &m);
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);
    int u, v, w;
    while (m--) {
	scanf("%d %d %d", &u, &v, &w);	
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
    }

    memset(dis + 1, 127, sizeof(int) * n);
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, 0});
    while (int size = q.size()) {
	while (size--) {
	    int val = q.top().first, u = q.top().second; q.pop();
	    if (dis[u] != val) continue;
	    for (P p : adj[u]) {
		int v = p.first, len = p.second;
		if (dis[u] + len < dis[v]) {
		    dis[v] = dis[u] + len;
		    q.push({dis[v], v});
		    pre[v].clear();
		    pre[v].emplace_back(u);
		}
		else if (dis[u] + len == dis[v])
		    pre[v].emplace_back(u);
	    }
	}
    }

    dfs(d);

    printf("%d %d", rst_send, 0);
    for (int i = rst_path.size() - 2; i >= 0; i--) {
	printf("->%d", rst_path[i]);
    }
    printf(" %d\n", rst_take);

    return 0;
}
