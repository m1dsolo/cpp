#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, mod = 1e6 + 7;

int arr[N], dp[N] = {1}, sum[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);
    // 01背包
    //for (int i = 0; i < n; i++) {
	//for (int j = m; j >= 1; j--) {
	    //for (int k = 1; k <= min(arr[i], j); k++)
		//dp[j] = (dp[j] + dp[j - k]) % mod;
	//}
    //}

    // 前缀和优化
    fill(sum, sum + m + 1, 1);
    for (int i = 0; i < n; i++) {
	for (int j = m; j >= 1; j--)
	    dp[j] = (dp[j] + sum[j - 1] - sum[j - min(arr[i], j) - 1] + mod) % mod;
	for (int j = 1; j <= m; j++)
	    sum[j] = (sum[j - 1] + dp[j]) % mod;
    }

    printf("%d\n", dp[m]);

    return 0;
}
