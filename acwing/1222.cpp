#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int dp[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    memset(dp, 0x3f, sizeof(dp));
    for (int i = n - 1; i >= 0; i--) {
	for (int j = 0; j < n; j++) {
	    if (i == j) dp[i][j] = 0;
	    else if (s[i] == s[j]) {
		if (i == j - 1) dp[i][j] = 0;
		else dp[i][j] = dp[i + 1][j - 1];
	    }
	    else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
	}
    }

    printf("%d\n", dp[0][n - 1]);

    return 0;
}
