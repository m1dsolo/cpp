#include <iostream>

using namespace std;

long long arr[1010][1010], sum[1010][1010];
int main() {
    int m, n, c;
    scanf("%d %d %d", &m, &n, &c);
    for (int i = 1; i <= m; i++) {
	for (int j = 1; j <= n; j++) {
	    scanf("%lld", &arr[i][j]);
	}
    }

    for (int i = 1; i <= m; i++) {
	for (int j = 1; j <= n; j++) {
	    sum[i][j] = sum[i - 1][j] - sum[i - 1][j - 1] + sum[i][j - 1] + arr[i][j];
	}
    }

    long long rst = sum[1][1], val;
    int rst_i = 1, rst_j = 1;
    c--;
    for (int i = 1; i <= m - c; i++) {
	for (int j = 1; j <= n - c; j++) {
	    if ((val = sum[i + c][j + c] - sum[i - 1][j + c] + sum[i - 1][j - 1] - sum[i + c][j - 1]) > rst) {
		rst = val;
		rst_i = i;
		rst_j = j;
	    }
	}
    }

    cout << rst_i << " " << rst_j << endl;

    return 0;
}
