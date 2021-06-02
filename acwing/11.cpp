#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10, mod = 1e9 + 7;

int dp1[N], dp2[N];	// dp1存前i个物品最大价值，dp2存前i个物品最大价值时的数量

int main() {
    int n, m, v, w;
    scanf("%d %d", &n, &m);
    fill(dp2, dp2 + m + 1, 1);
    for (int i = 0; i < n; i++) {
	scanf("%d %d", &v, &w);
	for (int j = m; j >= v; j--) {
	    int value = dp1[j - v] + w;
	    if (value == dp1[j])
		dp2[j] = (dp2[j] + dp2[j - v]) % mod;
	    else if (value > dp1[j]) {
		dp1[j] = value;
		dp2[j] = dp2[j - v];
	    }
	}
    }

    printf("%d\n", dp2[m]);

    return 0;
}
