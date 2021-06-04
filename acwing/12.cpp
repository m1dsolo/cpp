// 应该没办法优化成一维了把
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

struct item {
    int v;
    int w;
} items[N];

int dp[N][N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
	scanf("%d %d", &items[i].v, &items[i].w); 
    for (int i = n; i; i--) {
	for (int j = 0; j <= m; j++) {
	    dp[i][j] = dp[i + 1][j];
	    if (j >= items[i].v) dp[i][j] = max(dp[i][j], dp[i + 1][j - items[i].v] + items[i].w);
	}
    }

    int tot = m;
    for (int i = 1; i <= n; i++) {
	if (tot >= items[i].v && dp[i][tot] == dp[i + 1][tot - items[i].v] + items[i].w) {
	    printf("%d ", i);
	    tot -= items[i].v;
	}
    }
    printf("\n");

    return 0;
}
