#include <iostream>

using namespace std;

const int N = 1e4 + 10;

pair<int, int> arr[N];
int dp[N];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
	scanf("%d %d", &arr[i].first, &arr[i].second);

    for (int i = 0; i < n; i++) {
	for (int j = arr[i].second; j <= m; j++) {
	    dp[j] = max(dp[j], dp[j - arr[i].second] + arr[i].first);
	}
    }

    printf("%d\n", dp[m]);

    return 0;
}
