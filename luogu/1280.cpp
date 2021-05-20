#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> arr[10001];
int dp[10001], m[10001];

int main() {
    int n, k, a, b;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
	scanf("%d %d", &arr[i].first, &arr[i].second);
	m[arr[i].first]++;
    }
    sort(arr, arr + k, greater<pair<int, int>>());

    int ptr = 0;
    for (int i = n; i >= 1; i--) {
	if (!m[i])
	    dp[i] = dp[i + 1] + 1;
	else {
	    for (int j = 0; j < m[i]; j++) {
		dp[i] = max(dp[i], dp[i + arr[ptr++].second]);
	    }
	}
    }

    cout << dp[1] << endl;

    return 0;
}
