#include <iostream>

using namespace std;

const int N = 1e3 + 10;

pair<int, int> group[N][N];
int size[N];
int dp[N];

int main() {
    int m, n, a, b, c, cn = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
	scanf("%d %d %d", &a, &b, &c);
	group[c][++size[c]] = {a, b};
	cn = max(cn, c);
    }

    for (int i = 1; i <= cn; i++) {
	for (int j = m; j >= 0; j--) {
	    for (int k = 1; k <= size[i]; k++) {
		if (j - group[i][k].first >= 0)
		    dp[j] = max(dp[j], dp[j - group[i][k].first] + group[i][k].second);
	    }
	}
    }

    printf("%d\n", dp[m]);

    return 0;
}
