// pat甲级1018
#include <iostream>
#include <list>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
using P = pair<int, int>;

const int N = 510, INT_MAX = 2139062143;

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
    min_len = dis[d];

    return 0;
}
