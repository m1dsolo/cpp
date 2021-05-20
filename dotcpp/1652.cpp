#include <iostream>
#include <vector>

using namespace std;

int rst = 0;
//void dfs(int n) {
    //if (!n) {
	//rst++;
	//return;
    //}
    //if (n < 0) return;
    //dfs(n - 1);
    //dfs(n - 2);
//}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
	dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;

    return 0;
}
