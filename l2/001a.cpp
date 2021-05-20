// 最短路个数，路径最大和及其路径
#include <iostream>
#include <list>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;
using P = pair<int, int>;

const int N = 510;

int arr[N], dis[N], num[N], path[N], vals[N];
list<P> adj[510];

int n, m, s, d;

int main() {
    scanf("%d %d %d %d" ,&n, &m, &s, &d);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);
    int u, v, w;
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &u, &v, &w);
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
    }

    memset(dis, 127, sizeof(dis));
    memset(path, -1, sizeof(path));
    dis[s] = 0, num[s] = 1, vals[s] = arr[s];

    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, s});
    while (int size = q.size()) {
	while (size--) {
	    int val = q.top().first, u = q.top().second; q.pop();
	    if (val != dis[u]) continue;
	    for (P p : adj[u]) {
		int v = p.first, len = p.second;
		if (dis[u] + len < dis[v]) {
		    dis[v] = dis[u] + len;
		    q.push({dis[v], v});
		    path[v] = u;
		    num[v] = num[u];
		    vals[v] = vals[u] + arr[v];
		}
		else if (dis[u] + len == dis[v]) {
		    num[v] += num[u];
		    if (vals[u] + arr[v] > vals[v]) {
			vals[v] = vals[u] + arr[v];
			path[v] = u;
		    }
		}
	    }
	}
    }

    printf("%d %d\n", num[d], vals[d]);
    int ptr = d;
    stack<int> s;
    while (path[ptr] != -1) {
	s.emplace(path[ptr]);
	ptr = path[ptr];
    }
    while (s.size()) {
	printf("%d ", s.top());
	s.pop();
    }
    printf("%d\n", d);

    return 0;
}
