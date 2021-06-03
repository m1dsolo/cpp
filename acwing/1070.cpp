#include <iostream>

using namespace std;

const int N = 110;

int dp[N][N];

bool check(char c1, char c2) {
    return c1 == '(' && c2 == ')' || c1 == '[' && c2 == ']';
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
	for (int j = i; j < n; j++) {
	    if (i == j) dp[i][j] = 1;
	    else {
		dp[i][j] = 2e9;
		if (check(s[i], s[j])) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
		for (int k = i; k < j; k++)
		    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
	    }
	}
    }

    printf("%d\n", dp[0][n - 1]);

    return 0;
}
