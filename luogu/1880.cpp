// 环形区间dp，数组开两倍
// 可以用四边形不等式优化O(n ^ 3) -> O(n ^ 2): https://blog.csdn.net/noiau/article/details/72514812
#include <iostream>
#include <climits>

using namespace std;

const int N = 210;

int arr[N], sum[N], dp1[N][N], dp2[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf("%d", &arr[i]);
	arr[i + n] = arr[i];
    }

    for (int i = 1; i <= 2 * n; i++)
	sum[i] = sum[i - 1] + arr[i];

    for (int i = 2 * n; i >= 1; i--) {
	for (int j = i + 1; j <= 2 * n; j++) {
	    dp2[i][j] = INT_MAX;
	    for (int k = i; k < j; k++) {
		dp1[i][j] = max(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + sum[j] - sum[i - 1]);
		dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + sum[j] - sum[i - 1]);
	    }
	}
    }

    int max_rst = 0, min_rst = INT_MAX;
    for (int i = 1; i <= n; i++) {
	max_rst = max(max_rst, dp1[i][i + n - 1]);
	min_rst = min(min_rst, dp2[i][i + n - 1]);
    }
    printf("%d\n%d\n", min_rst, max_rst);

    return 0;
}
