// https://www.cnblogs.com/lr599909928/p/14800126.html
#include <iostream>

using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;

int dp[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    dp[k] = 1;
    for (int i = k + 1; i <= n; i++)
	dp[i] = (dp[i - 1] + dp[i - k]) % mod;

    printf("%d\n", dp[n]);

    return 0;
}
