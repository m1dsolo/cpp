#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
	int val;
	cin >> val;
	v[i] = val;
    }

    vector<int> dp(v.size(), 1);
    int rst = 1;
    for (int i = 0; i < v.size(); i++) {
	for (int j = 0; j < i; j++) {
	    if (v[i] >= v[j]) {
		dp[i] = max(dp[i], dp[j] + 1);
		rst = max(rst, dp[i]);
	    }
	}
    }

    cout << rst << endl;

    return 0;
}
