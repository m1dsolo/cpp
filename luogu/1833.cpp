#include <iostream>

using namespace std;

struct item {
    int v;
    int w;
    bool flag;
} items[(int)1e6];	// 多重背包二进制优化时记得开大点数组

int cnt, dp[(int)1e3 + 10];

int main() {
    int h1, m1, h2, m2, n;
    scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &n);
    int W = (h2 - h1) * 60 + m2 - m1;

    int v, w, c;
    for (int i = 0; i < n; i++) {
	scanf("%d %d %d", &w, &v, &c);
	if (c) {
	    for (int j = 1; j <= c; j <<= 1) {
		items[cnt++] = {v * j, w * j, true};
		c -= j;
	    }
	    if (c)
		items[cnt++] = {v * c, w * c, true};
	}
	else
	    items[cnt++] = {v, w, false};
    }

    for (int i = 0; i < cnt; i++) {
	if (items[i].flag) {
	    for (int j = W; j >= items[i].w; j--)
		dp[j] = max(dp[j], dp[j - items[i].w] + items[i].v);
	}
	else for (int j = items[i].w; j <= W; j++)
	    dp[j] = max(dp[j], dp[j - items[i].w] + items[i].v);
    }

    printf("%d\n", dp[W]);

    return 0;
}
