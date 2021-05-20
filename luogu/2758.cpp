#include <iostream>

using namespace std;

int dp[2000][2000];
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length(), n = s2.length();
    for (int i = 1; i <= m; i++)
	dp[i][0] = i;
    for (int j = 1; j <= n; j++)
	dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
	for (int j = 1; j <= n; j++) {
	    dp[i][j] = s1[i - 1] == s2[j - 1] ? dp[i - 1][j - 1] : min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
	}
    }

    cout << dp[m][n] << endl;

    return 0;
}
