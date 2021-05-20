#include <iostream>
#include <vector>

using namespace std;

string max_palindrome(const string &s) {
    int len = s.length();
    if (len < 2) return s;

    vector<vector<bool>> dp(len, vector<bool>(len, false));
    
    int rst_i = 0, rst_len = 1;
    for (int i = len - 1; i >= 0; i--) {
	for (int j = i; j < len; j++) {
	    dp[i][j] = s[i] == s[j];
	    if (j - i > 1)
		dp[i][j] = dp[i][j] & dp[i + 1][j - 1];

	    int tmp = j - i + 1;
	    if (dp[i][j] && tmp > rst_len) {
		rst_len = tmp;
		rst_i = i;
	    }
	}
    }

    return s.substr(rst_i, rst_len);
}

int main() {
    cout << max_palindrome("abbccbbdd") << endl;

    return 0;
}
