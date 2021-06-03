#include <iostream>

using namespace std;
using ll = long long;

const int N = 55, M = 15, mod = 1e9 + 7;

int arr[N][N], dp[N][N][M][M];

int main() {
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= m; j++) {
	    scanf("%d", &arr[i][j]);
	    arr[i][j]++;
	} 
    }

    dp[1][1][0][0] = 1, dp[1][1][1][arr[1][1]] = 1;
    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= m; j++) {
	    for (int cnt = 0; cnt <= c; cnt++) {
		for (int k = 0; k < M; k++) {
		    dp[i][j][cnt][k] = ((ll)dp[i][j][cnt][k] + dp[i - 1][j][cnt][k] + dp[i][j - 1][cnt][k]) % mod;
		    if (cnt && k == arr[i][j]) {
			for (int l = 0; l < k; l++)
			    dp[i][j][cnt][k] = ((ll)dp[i][j][cnt][k] + dp[i - 1][j][cnt - 1][l] + dp[i][j - 1][cnt - 1][l]) % mod;
		    }
		}
	    }
	}
    }

    int rst = 0;
    for (int i = 1; i < M; i++)
	rst = (rst + dp[n][m][c][i]) % mod;

    printf("%d\n", rst);

    return 0;
}
