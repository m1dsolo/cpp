#include <iostream>

using namespace std;

const int N = 11;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	int m, n;
	scanf("%d %d", &m, &n);
	int dp[N][N] = {1};
	for (int i = 0; i <= m; i++) {
	    for (int j = 1; j <= n; j++) {
		dp[i][j] = dp[i][j - 1];
		if (i >= j) dp[i][j] += dp[i - j][j];
	    }
	}
	printf("%d\n", dp[m][n]);
    }

    return 0;
}
