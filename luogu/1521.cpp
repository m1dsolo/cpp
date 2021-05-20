#include <iostream>

using namespace std;

// dp[i][j] = sum(dp[i - 1][max(0, j - (i - 1)) ~ j])
// 意思是每新加一个i，可以比之前逆序对多0 ~ (i - 1)个，0就是插最右面，i - 1就是插最左面
int dp[110][5000];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
	dp[i][0] = 1;
	for (int j = 1; j <= min(i * (i - 1) / 2, m); j++) {	// 假如i = 5，最多逆序对就是{5, 4, 3, 2, 1}这种情况，有(1 + 2 + 3 + 4)个最多，所以后面不用计算了。
	    for (int k = max(0, j - i + 1); k <= j; k++)
		dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10000;
	}
    }
    cout << dp[n][m] << endl;

    return 0;
}
