#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int dp[2][3];

int main() {
    int i = 0;
    char c;
    while (scanf("%c", &c) != EOF && isdigit(c)) {
	int k = (c - '0') % 3;
	for (int j = 0; j < 3; j++)
	    dp[i ^ 1][j] = (dp[i][j] + dp[i][(3 + j - k) % 3]) % mod;	    // 不选c和选c
	dp[i ^= 1][k]++;
    }

    printf("%d\n", dp[i][0]);

    return 0;
}
