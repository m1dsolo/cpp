#include <iostream>

using namespace std;

struct item {
    int v;
    int m;
    int val;
} items[60];

int dp[500][500];

int main() {
    int v, m, n;
    scanf("%d %d", &v, &m);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d %d %d", &items[i].v, &items[i].m, &items[i].val);

    for (int i = 0; i < n; i++) {
	for (int j = v; j >= items[i].v; j--) {
	    for (int k = m; k >= items[i].m; k--) {
		dp[j][k] = max(dp[j][k], dp[j - items[i].v][k - items[i].m] + items[i].val);
	    }
	}
    }

    printf("%d\n", dp[v][m]);

    return 0;
}
