#include <iostream>

using namespace std;

const int N = 40;

int dp[2][N];

int main() {
    int n, m, k = 0;
    scanf("%d %d", &n, &m);
    dp[0][0] = 1;
    while (m--) {
	for (int i = 0; i < n; i++) {
	    dp[k ^ 1][(i - 1 + n) % n] += dp[k][i];
	    dp[k ^ 1][(i + 1) % n] += dp[k][i];
	    dp[k][i] = 0;
	}
	k ^= 1;
    }

    printf("%d\n", dp[k][0]);

    return 0;
}
