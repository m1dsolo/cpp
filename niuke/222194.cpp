// WA!!!
#include <iostream>

using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;

int dp[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    dp[0] = 1;
    for (int i = k; i <= n; i++)	// 错误的!!!,k == 1时会导致dp[1] = 2，其实应该为1
	dp[i] = (dp[i - 1] + dp[i - k]) % mod;

    printf("%d\n", dp[n]);

    return 0;
}
