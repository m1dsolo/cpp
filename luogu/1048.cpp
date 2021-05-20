#include <iostream>

using namespace std;

int arr[101][2];
int dp[1001];
int main() {
    int t, m;
    cin >> t >> m;
    for (int i = 0; i < m; i++) {
	scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for (int i = 0; i < m; i++) {
	for (int j = t; j >= arr[i][0]; j--) {
	    dp[j] = max(dp[j], dp[j - arr[i][0]] + arr[i][1]);
	}
    }

    cout << dp[t] << endl;

    return 0;
}
