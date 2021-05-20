// luogu 4141, bzoj 2287
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n;
int arr[N], dp1[N] {1}, dp2[N] {1}; // dp1[i]为学分恰好为i的方法总数，dp2[i]为不选j课学分恰好为i的方案总数

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
	scanf("%d", &arr[i]);
	for (int j = m; j >= arr[i]; j--)
	    dp1[j] = (dp1[j] + dp1[j - arr[i]]) % 10;
    }

    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= min(arr[i] - 1, m); j++)	// arr[i]有可能大于m
	    printf("%d", dp2[j] = dp1[j]);  // 总学分太少了，不可能选到挂的这课
	for (int j = arr[i]; j <= m; j++)
	    printf("%d", dp2[j] = (dp1[j] - dp2[j - arr[i]] + 10) % 10);    // 不选方法 = 总方法 - 选方法(不选方法j，然后再选上)
	printf("\n");
    }

    return 0;
}
