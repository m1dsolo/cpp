#include <iostream>
#include <list>
#include <queue>
#include <cstring>

using namespace std;

using P = pair<int, int>;
list<P> adj[100001];
int dis[200001];

int main() {
    int n, m, s, u, v, w;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &u, &v, &w);
	adj[u].push_back({v, w});
    }

    memset(dis, 127, sizeof(int) * (n + 1));

    dis[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, s});

    while (int size = q.size()) {
	while (size--) {
	    int val = q.top().first, begin = q.top().second; q.pop();
	    if (val != dis[begin]) continue;
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
