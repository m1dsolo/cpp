#include <iostream>

using namespace std;

const int N = 2e4 + 10;

int arr[N][2], dp[N][2];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d %d", &arr[i][0], &arr[i][1]);

    dp[0][0] = arr[0][0] - 1 + 2 * (arr[0][1] - arr[0][0]), dp[0][1] = arr[0][1] - 1;
    for (int i = 1; i < n; i++) {
	int len = arr[i][1] - arr[i][0];
	dp[i][0] = min(dp[i - 1][0] + abs(arr[i - 1][0] - arr[i][1]), dp[i - 1][1] + abs(arr[i - 1][1] - arr[i][1])) + len;
	dp[i][1] = min(dp[i - 1][0] + abs(arr[i - 1][0] - arr[i][0]), dp[i - 1][1] + abs(arr[i - 1][1] - arr[i][0])) + len;
    }

    printf("%d\n", min(dp[n - 1][0] + n - arr[n - 1][0], dp[n - 1][1] + n - arr[n - 1][1]) + n - 1);

    return 0;
}
