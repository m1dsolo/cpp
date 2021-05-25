#include <iostream>
#include <cstring>

using namespace std;

const int N = 60;

int n;
int dp[N][N][2], loc[N], sum[N];

int cost(int i, int j, int l, int r) {
    return (loc[j] - loc[i]) * (sum[n] - (sum[r] - sum[l - 1]));
}

int main() {
    int c, a;
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++) {
	scanf("%d %d", &loc[i], &a);
	sum[i] = sum[i - 1] + a;
    }

    memset(dp, 63, sizeof(dp));		// 要初始化INT_MAX主要是因为：假如dp[3][4]会用到dp[4][4]，而dp[4][4]没初始化INT_MAX的话，肯定就不对了
    dp[c][c][0] = 0, dp[c][c][1] = 0;
    for (int i = c; i; i--) {
	for (int j = i + 1; j <= n; j++) {
	    dp[i][j][0] = min(dp[i + 1][j][0] + cost(i, i + 1, i + 1, j), dp[i + 1][j][1] + cost(i, j, i + 1, j));
	    dp[i][j][1] = min(dp[i][j - 1][0] + cost(i, j, i, j - 1), dp[i][j - 1][1] + cost(j - 1, j, i, j - 1));
	}
    }

    printf("%d\n", min(dp[1][n][0], dp[1][n][1]));

    return 0;
}
