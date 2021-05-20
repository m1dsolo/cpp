#include <iostream>

using namespace std;

int arr[(int)1e4 + 1][2];
long long dp[(int)1e7 + 1];
int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    for (int i = 0; i < m; i++) {
	scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for (int i = 0; i < m; i++) {
	for (int j = arr[i][0]; j <= t; j++) {
	    dp[j] = max(dp[j], dp[j - arr[i][0]] + arr[i][1]);
	}
    }

    cout << dp[t] << endl;

    return 0;
}
