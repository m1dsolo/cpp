#include <iostream>

using namespace std;

const int N = 3e4 + 10;

pair<int, int> arr[30];
int dp[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
	scanf("%d %d", &arr[i].first, &arr[i].second);

    for (int i = 0; i < m; i++) {
	for (int j = n; j >= arr[i].first; j--) {
	    dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].first * arr[i].second);
	}
    }

    printf("%d\n", dp[n]);

    return 0;
}
