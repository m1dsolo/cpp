// https://www.luogu.com.cn/blog/Ning-H/solution-p3146
#include <iostream>

using namespace std;

const int N = 260;

int dp[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &dp[i][i]);
    // 有更优O(n ** 2)解法
    for (int i = n - 2; i >= 0; i--) {
	for (int j = i + 1; j < n; j++) {
	    for (int k = i; k < j; k++)
		if (dp[i][k] == dp[k + 1][j] && dp[i][k]) dp[i][j] = max(dp[i][j], dp[i][k] + 1);   // 注意要与上dp[i][k]，因为dp[i][k] == dp[k + 1][j] == 0不应该更新结果
	}
    }

    int rst = 0;
    for (int i = 0; i < n; i++) {
	for (int j = i; j < n; j++)
	    rst = max(rst, dp[i][j]);
    }

    printf("%d\n", rst);

    return 0;
}
