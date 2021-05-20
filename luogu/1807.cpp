#include <iostream>
#include <list>
#include <queue>
#include <cstring>

using namespace std;

const int INT_MIN = -2139062144;
const int N = 1510;
int adj[N][N];
int dp[N], ind[N];

// 可能有负边和重边
// 拓扑排序
int main() {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    memset(adj, 128, (N * N) * sizeof(int));
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &a, &b, &c);
	if (adj[a][b] == INT_MIN) {
	    adj[a][b] = c;
	    ind[b]++;
	}
	adj[a][b] = max(adj[a][b], c);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
	if (!ind[i]) {
	    q.emplace(i);
	}
    }

    memset(dp + 1, 128, n * sizeof(int));
    dp[1] = 0;
    while (int size = q.size()) {
	while (size--) {
	    int a = q.front(); q.pop();
	    for (int b = 1; b <= n; b++) {
		if (adj[a][b] != INT_MIN) {
		    if (!--ind[b]) {
			q.emplace(b);
		    }
		    dp[b] = max(dp[b], dp[a] + adj[a][b]);
		}
	    }
	}
    }

    cout << (dp[n] == INT_MIN ? -1 : dp[n]) << endl;

    return 0;
}
