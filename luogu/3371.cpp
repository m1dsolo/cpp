#include <iostream>
#include <list>
#include <queue>
#include <climits>

using namespace std;

using P = pair<int, int>;
list<P> adj[10001];
int dis[10001];

int main() {
    int n, m, s, u, v, w;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &u, &v, &w);
	adj[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++)
	dis[i] = INT_MAX;
    dis[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, s});

    while (int size = q.size()) {
	while (size--) {
	    int val = q.top().first, begin = q.top().second; q.pop();
	    for (P p : adj[begin]) {
		if (dis[begin] + p.second < dis[p.first]) {
		    dis[p.first] = dis[begin] + p.second;
		    q.push({dis[p.first], p.first});
		}
	    }
	}
    }

    for (int i = 1; i <= n; i++)
	printf("%d ", dis[i]);
    printf("\n");

    return 0;
}
