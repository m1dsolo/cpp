#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    int g = gcd(a, b);
    return a * b / g;
}

int main() {
    int n = 2021;
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
	for (int j = 1; j <= 21; j++) {
	    if (i - j > 0) dp[i] = min(dp[i], dp[i - j] + lcm(i, j));
	}
    }
    cout << dp[n] << endl;

    return 0;
}
