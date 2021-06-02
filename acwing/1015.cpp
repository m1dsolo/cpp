#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int arr[N][N], dp[N][N];

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= m; j++)
		scanf("%d", &arr[i][j]);
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= m; j++)
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
	}
	printf("%d\n", dp[n][m]);
    }

    return 0;
}
