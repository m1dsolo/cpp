#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
struct item {
    int v;
    int w;
    bool flag;	    // true is 01
} items[N];

int dp[N];

int main() {
    int a, m, v, w, f;
    scanf("%d %d", &a, &m);
    for (int i = 0; i < a; i++) {
	scanf("%d %d %d", &v, &w, &f);
	if (f <= 0) items[n++] = {v, w, f};
	else {
	    for (int j = 1; j <= f; j <<= 1) {
		items[n++] = {v * j, w * j, true};
		f -= j;
	    }
	    if (f) items[n++] = {v * f, w * f, true};
	}
    }

    for (int i = 0; i < n; i++) {
	if (items[i].flag) for (int j = m; j >= items[i].v; j--)
	    dp[j] = max(dp[j], dp[j - items[i].v] + items[i].w);
	else for (int j = items[i].v; j <= m; j++)
	    dp[j] = max(dp[j], dp[j - items[i].v] + items[i].w);
    }

    printf("%d\n", dp[m]);

    return 0;
}
