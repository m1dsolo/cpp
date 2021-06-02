#include <iostream>

using namespace std;

const int N = 1e6 + 10;

struct item {
    int v;
    int w;
} items[N];

int cnt, dp[N];

int main() {
    int n, m, v, w, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
	scanf("%d %d %d", &v, &w, &c);
	for (int j = 1; j <= c; j <<= 1) {
	    items[++cnt] = {j * v, j * w};
	    c -= j;
	}
	if (c)
	    items[++cnt] = {c * v, c * w};
    }

    for (int i = 1; i <= cnt; i++) {
	for (int j = m; j >= items[i].v; j--)
	    dp[j] = max(dp[j], dp[j - items[i].v] + items[i].w);
    }

    printf("%d\n", dp[m]);

    return 0;
}
