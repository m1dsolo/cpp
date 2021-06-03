#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int dp[2][N];

int main() {
    int n, m, a, k = 0;
    scanf("%d %d", &n, &m);
    memset(dp, -0x3f, sizeof(dp));	// 必须初始化为负，防止dp[0][0 ~ m]全可以取
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
	scanf("%d", &a);
	for (int j = 0; j < m; j++)
	    dp[k ^ 1][j] = max(dp[k][j], dp[k][(j - a % m + m) % m] + a);
	k ^= 1;
    }

    printf("%d\n", dp[k][0]);

    return 0;
}
