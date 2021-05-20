#include <iostream>
#include <list>
#include <queue>
#include <cstring>

using namespace std;
using P = pair<int, int>;

const int INT_MIN = -2139062144;
const int N = 1510;
int adj[N][N];
int dis[N];

// 可能有负边和重边
// dijkstra
int main() {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    memset(dis + 1, 128, n * sizeof(int));
    dis[1] = 0;
    memset(adj, 128, (N * N) * sizeof(int));
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &a, &b, &c);
	adj[a][b] = max(adj[a][b], c);
    }

    priority_queue<P, vector<P>> q;
    q.push({0, 1});
    while (int size = q.size()) {
	while (size--) {
	    int val = q.top().first, begin = q.top().second; q.pop();
	    if (val != dis[begin]) continue;
	    for (int end = 1; end <= n; end++) {
		if (adj[begin][end] != INT_MIN && dis[begin] + adj[begin][end] > dis[end]) {
		    dis[end] = dis[begin] + adj[begin][end];
		    q.push({dis[end], end});
		}
	    }
	}
    }

    cout << (dis[n] == INT_MIN ? -1 : dis[n]) << endl;

    return 0;
}
