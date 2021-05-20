#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int max_val = 0;
    for (int i = 0; i < n; i++) {
	cin >> nums[i];
	max_val = max(max_val, nums[i]);
    }
    int g = 0;
    for (int i = 0; i < n; i++)
	g = gcd(g, nums[i]);

    if (g != 1) {
	cout << "INF" << endl;
	return 0;
    }

    int m = max_val * (max_val - 2);
    vector<bool> dp(m + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
	for (int j = nums[i]; j <= m; j++) {
	    dp[j] = dp[j] | dp[j - nums[i]];
	}
    }

    int rst = 0;
    for (int i = 1; i <= m; i++) {
	if (!dp[i]) rst++;
    }

    cout << rst << endl;

    return 0;
}
