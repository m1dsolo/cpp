// 区间dp
#include <iostream>

using namespace std;

const int N = 5e3 + 10;

int arr[N], dp[N][N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);

    for (int i = n; i >= 1; i--) {
	for (int j = i; j <= n; j++) {
	    dp[i][j] = max(arr[i] ^ arr[j], max(dp[i + 1][j], dp[i][j - 1]));
	}
    }

    int l, r;
    while (m--) {
	scanf("%d %d", &l, &r);	
	printf("%d\n", dp[l][r]);
    }

    return 0;
}
