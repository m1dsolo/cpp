#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e3 + 10, mod = 1e9 + 7;

int dp[2][N];	    // dp[i][j]数列长度为i，最大元素为j(滚动数组优化后)

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    fill(dp[0] + 1, dp[0] + 1 + n, 1);
    int i = 0;
    while (m--) {
	for (int j = 1; j <= n; j++) {
	    for (int k = 1; k <= j; k++)
		if (!(j % k)) dp[i ^ 1][j] = (dp[i ^ 1][j] + dp[i][k]) % mod;
	}
	i ^= 1;
    }

    int rst = 0;
    for (int j = 1; j <= n; j++)
	rst = (rst + dp[i][j]);
    printf("%d\n", rst);

    return 0;
}
