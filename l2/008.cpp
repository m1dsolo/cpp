#include <iostream>

using namespace std;

int dp[1010][1010];
int main() {
    string s;
    getline(cin, s);
    int n = s.length();

    int rst = 1;
    for (int i = n - 1; i >= 0; i--) {
	for (int j = i; j < n; j++) {
	    if (i == j) dp[i][j] = 1;
	    else if (s[i] == s[j])
		rst = max(rst, dp[i][j] = dp[i + 1][j - 1] + 2);
	}
    }

    cout << rst << endl;

    return 0;
}
