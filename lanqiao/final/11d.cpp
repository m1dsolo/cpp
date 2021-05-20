#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
	for (int j = 0; j < i; j++) {
	    if (s[j] < s[i])
		dp[i] += dp[j];
	    else if (s[j] == s[i])
		dp[i] -= dp[j];
	}
    }

    int rst = 0;
    for (int a : dp)
	rst += a;

    cout << rst << endl;

    return 0;
}
