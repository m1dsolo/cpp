#include <iostream>

using namespace std;

const int N = 110;

int vs[N][N], wts[N][N], dp[N];
int sz[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
	scanf("%d", &sz[i]);	
	for (int j = 0; j < sz[i]; j++)
	    scanf("%d %d", &vs[i][j], &wts[i][j]);
    }

    for (int i = 0; i < n; i++) {
	for (int j = m; j >= 0; j--) {
	    for (int k = 0; k < sz[i]; k++) {
		if (j >= vs[i][k])
		    dp[j] = max(dp[j], dp[j - vs[i][k]] + wts[i][k]);
	    }
	}
    }

    printf("%d\n", dp[m]);

    return 0;
}
