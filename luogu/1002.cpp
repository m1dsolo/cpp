#include <iostream>
#include <vector>

using namespace std;

int xy[9][2] = {{0, 0}, {-2, -1}, {-1, -2}, {2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {2, 1}, {1, 2}};
int main() {
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
    for (int i = 0; i < 9; i++) {
	int xx = x + xy[i][0];
	int yy = y + xy[i][1];
	if (xx < 0 || yy < 0 || xx > m || yy > n) continue;
	dp[xx][yy] = -1;
    }

    for (int i = 0; i <= m; i++) {
	if (dp[i][0] == -1) break;
	dp[i][0] = 1;
    }
    for (int j = 0; j <= n; j++) {
	if (dp[0][j] == -1) break;
	dp[0][j] = 1;
    }
    for (int i = 1; i <= m; i++) {
	for (int j = 1; j <= n; j++) {
	    if (dp[i][j] == -1) continue;
	    dp[i][j] = max(dp[i - 1][j], 0ll) + max(dp[i][j - 1], 0ll);
	}
    }

    cout << dp[m][n] << endl;

    return 0;
}
