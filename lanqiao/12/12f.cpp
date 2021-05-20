#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.length(), n = t.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int j = 1; j <= n; j++)
	dp[0][j] = INT_MAX - 10;
    for (int i = 1; i <= m; i++) {
	for (int j = 1; j <= n; j++) {
	    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
	}
    }
    cout << dp[m][n] << endl;

    return 0;
}
