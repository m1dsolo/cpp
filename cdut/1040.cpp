#include <iostream>
#include <list>
#include <queue>
#include <cstring>

using namespace std;
using P = pair<int, int>;

const int N = 5e3 + 10;

int dis1[N], dis2[N];
list<P> adj[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int u, v, w;
    while (m--) {
	scanf("%d %d %d", &u, &v, &w);
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
    }
    memset(dis1 + 2, 127, sizeof(int) * (n - 1));
    memset(dis2 + 1, 127, sizeof(int) * (n - 1));

    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, 1});
    while (int size = q.size()) {
	while (size--) {
	    int val = q.top().first, u = q.top().second; q.pop();
	    if (val > dis2[u]) continue;
	    for (P p : adj[u]) {
		int v = p.first, len = p.second;
		if (val + len < dis1[v]) {
		    dis2[v] = dis1[v];
		    dis1[v] = val + len;
		    q.push({dis1[v], v});
		}
		if (val + len < dis2[v] && val + len > dis1[v]) {
		    dis2[v] = val + len;
		    q.push({dis2[v], v});
		}
	    }
	}
    }

    printf("%d\n", dis2[n]);

    return 0;
}
