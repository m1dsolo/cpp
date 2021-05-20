// leetcode 10
// not know it very much

#include <iostream>
#include <vector>

using namespace std;

bool is_match(const string &s, const string &p) {
    int len_s = s.length(), len_p = p.length();
    if (!len_p) return !len_s;
    else if (!len_s && len_p == 1) return false;
    vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));	    // s前i个能否被p前j个匹配
    dp[0][0] = true;
    for (int j = 0; j < len_p; j++)
	dp[0][j + 1] = (p[j] == '*' && dp[0][j - 1]);
    
    for (int i = 0; i < len_s; i++) {
	for (int j = 0; j < len_p; j++) {
	    if (s[i] == p[j] || p[j] == '.') dp[i + 1][j + 1] = (i > 0 && j > 0) ? dp[i][j] : true;
	    else if (p[j] == '*') {
		if (p[j - 1] != s[i] && p[j - 1] != '.') dp[i + 1][j + 1] = dp[i + 1][j - 1];
		else if (p[j - 1] == s[i] || p[j - 1] == '.')
		    dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
	    }
	}
    }

    return dp[len_s][len_p];
}

int main() {
    cout << is_match("", ".*") << endl;

    return 0;
}
