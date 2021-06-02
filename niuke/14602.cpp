#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e3 + 10;

struct item {
    int v;
    int w;
};

item group[N][N];
int dp[N], size[N];

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
	    scanf("%d", &size[i]);
	    for (int j = 0; j < size[i]; j++)
		scanf("%d", &group[i][j].v);
	    for (int j = 0; j < size[i]; j++)
		scanf("%d", &group[i][j].w);
	}
	memset(dp + 1, 0, sizeof(int) * m);
	for (int i = 0; i < n; i++) {
	    for (int j = m; j >= 0; j--) {
		for (int k = 0; k < size[i]; k++)
		    if (j >= group[i][k].w) dp[j] = max(dp[j], dp[j - group[i][k].w] + group[i][k].v);
	    }
	}
	printf("%d\n", dp[m]);
    }

    return 0;
}
