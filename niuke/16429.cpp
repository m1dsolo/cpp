#include <iostream>

using namespace std;
using ll = long long;

const int N = 2e3 + 10;

int dp[N][N] = {1};
int sum[N][N];

int main() {
    int t, k;
    scanf("%d %d", &t, &k);
    for (int i = 1; i <= 2000; i++) {
	dp[i][0] = 1;
	for (int j = 1; j <= i; j++)
	    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % k + k;
    }

    for (int i = 1; i <= 2000; i++) {
	for (int j = 1; j <= 2000; j++) {
	    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (dp[i][j] && !(dp[i][j] % k));
	}
    }

    int n, m;
    while (t--) {
	scanf("%d %d", &n, &m);
	printf("%d\n", sum[n][m]);
    }

    return 0;
}
