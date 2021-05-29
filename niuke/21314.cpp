#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;
struct q {
    ll p;
    ll d;
    ll t;
} qs[60];

ll dp[N];

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++)
	scanf("%lld", &qs[i].p);
    for (int i = 0; i < n; i++)
	scanf("%lld", &qs[i].d);
    for (int i = 0; i < n; i++)
	scanf("%lld", &qs[i].t);

    sort(qs, qs + n, [](const q &q1, const q &q2) {	    // 这么贪心一定对吗？
	return (double)q1.d / q1.t > (double)q2.d / q2.t;
    });

    ll rst = 0;
    for (int i = 0; i < n; i++) {
	for (int j = t; j >= qs[i].t; j--)
	    rst = max(rst, dp[j] = max(dp[j], dp[j - qs[i].t] + qs[i].p - qs[i].d * j));    // max不一定在dp[t]因为dp[t]是消耗正好t时间的值，最值可能在消耗比t少的位置
    }

    printf("%lld\n", rst);

    return 0;
}
