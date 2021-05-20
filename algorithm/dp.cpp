#include <iostream>

using namespace std;

string longest_palindrome_substr(string &s) {
    int n = s.length();
    int start = 0, max_len = 1;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; i--) {
	for (int j = i; j < n; j++) {
	    if (i == j) dp[i][j] = 1;
	    else if (s[i] == s[j]) {
		dp[i][j] = dp[i + 1][j - 1] + 2;
		if (dp[i][j] > max_len) {
		    max_len = dp[i][j];
		    start = i;
		}
	    }
	}
    }
    return s.substr(start, max_len);
}

int longest_palindrome_subseq(string &s) {
    int n = s.length();
    int start = 0, max_len = 1;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; i--) {
	for (int j = i; j < n; j++) {
	    dp[i][j] = s[i] == s[j];
	    if (j - i > 2)
		dp[i][j] = dp[i][j] & dp[i + 1][j - 1];
	    if (dp[i][j] && j - i >= max_len) {
		max_len = j - i + 1;
		start = i;
	    }
	}
    }
    return s.substr(start, max_len);
}

int max_subseq(vector<int> &v) {
    int rst = INT_MIN;
    for (int a : v) {
	rst = max(max(rst, a), rst + a);
    }
    return rst;
}

// 包括了空subarray
int max_subarray(vector<int> &v) {
    int rst = INT_MIN, dp = INT_MIN;
    for (int a : v) {
	dp = max(dp, 0) + a;
	rst = max(rst, dp);
    }
    return rst;
}

int main() {

}
