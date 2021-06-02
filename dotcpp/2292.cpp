#include <iostream>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

const int N = 110;

int n, m; 
ll dp[2][N][N], sum[N][N], f[N][N];
bool arr[N][N];

void update(int i) {
    for (int j = 1; j <= m; j++)
	for (int k = 1; k <= m; k++)
	    f[j][k] = (f[j - 1][k] + f[j][k - 1] - f[j - 1][k - 1] + dp[i][j][k]) % mod;
}

int get(int x1, int y1, int x2, int y2) {
    return (f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1]) % mod;
}

int main() {
    char c;
    string s;
    scanf("%d %d", &n, &m);
    getline(cin, s);
    for (int i = n; i; i--) {
	for (int j = 1; j <= m; j++) {
	    scanf("%c", &c);
	    arr[i][j] = c == 'X';
	    sum[i][j] = sum[i][j - 1] + arr[i][j];
	}
	getline(cin, s);
    }

    dp[0][1][m] = 1;
    update(0);
    int rst = 1, i = 0;
    for (int l = 1; l <= n; l++) {
	for (int j = 1; j <= m; j++) {
	    for (int k = j; k <= m; k++) {
		if (sum[l][k] == sum[l][j - 1])
		    dp[i ^ 1][j][k] = get(1, k, j, m) % mod;
		else
		    dp[i ^ 1][j][k] = 0;
		rst = (rst + dp[i ^ 1][j][k]) % mod;
	    }
	}
	update(i ^= 1);
    }

    printf("%d\n", (rst + mod) % mod);

    return 0;
}
