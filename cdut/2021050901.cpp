#include <iostream>
#include <cstring>

using namespace std;

const int N = 3e2 + 10;
const long long LONG_MAX = 9187201950435737471;

long long dp[N][N];
int adj[N][N];

int main() {
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    memset(dp, 127, sizeof(dp));
    for (int i = 1; i <= n; i++)
	dp[i][i] = 0;

    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &u, &v, &w);
	dp[u][v] = w;
	dp[v][u] = w;
	adj[u][v] = w;
	adj[v][u] = w;
    }

    for (int k = 1; k <= n; k++) {
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++) {
		if (dp[i][k] != LONG_MAX && dp[k][j] != LONG_MAX)
		    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	    }
	}
    }

    int q, u1, v1, w1, u2, v2, w2;
    scanf("%d", &q);
    while (q--) {
	scanf("%d %d %d %d %d %d", &u1, &v1, &w1, &u2, &v2, &w2);
	long long rst = LONG_MAX;
	int ww1 = adj[u1][v1] - w1, ww2 = adj[u2][v2] - w2;
	rst = min(rst, dp[u1][u2] + w1 + w2);
	rst = min(rst, dp[u1][v2] + w1 + ww2);
	rst = min(rst, dp[v1][u2] + ww1 + w2);
	rst = min(rst, dp[v1][v2] + ww1 + ww2);
	printf("%lld\n", rst == LONG_MAX ? -1 : rst);
    }

    return 0;
}
