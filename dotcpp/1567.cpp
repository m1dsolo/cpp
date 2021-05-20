#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> dp(n + 1, false);
    for (int i = 0; i < m; i++) {
	int val;
	cin >> val;
	dp[val] = true;
    }

    int left = 0, right = 1;
    for (int i = 2; i < dp.size(); i++) {
	int tmp = 0;
	if (!dp[i]) {
	    tmp += left + right;
	}
	left = right;
	right = tmp;
    }

    cout << right << endl;

    return 0;
}
