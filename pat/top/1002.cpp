// 带点限制的01背包
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 60;

struct pj {
    int p;
    int l;
    int d;
} pjs[N];

int dp[(int)5e6];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d %d %d", &pjs[i].p, &pjs[i].l, &pjs[i].d);
    sort(pjs, pjs + n, [](const pj &p1, const pj &p2) {
	return p1.d < p2.d;
    });

    int w = pjs[n - 1].d;
    for (int i = 0; i < n; i++) {
	for (int j = w; j >= pjs[i].l; j--)
	    if (j <= pjs[i].d) dp[j] = max(dp[j], dp[j - pjs[i].l] + pjs[i].p);	    // 不一定能选
    }

    int rst = 0;
    for (int i = 0; i <= w; i++)	// 答案不一定在dp[w]
	rst = max(rst, dp[i]);
    printf("%d\n", rst);

    return 0;
}
