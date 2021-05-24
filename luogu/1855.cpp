#include <iostream>

using namespace std;

const int N = 210;
pair<int, int> arr[110];
int dp[N][N];

int main() {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 0; i < n; i++)
	scanf("%d %d", &arr[i].first, &arr[i].second);

    for (int i = 0; i < n; i++) {
	for (int j = m; j >= arr[i].first; j--) {
	    for (int k = t; k >= arr[i].second; k--)
		dp[j][k] = max(dp[j][k], dp[j - arr[i].first][k - arr[i].second] + 1);
	}
    }

    printf("%d\n", dp[m][t]);

    return 0;
}
