#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e4 + 10;

int arr[110][110];
pair<int, int> group[110][110];
int dp[N];

int main() {
    int s, n, m;
    scanf("%d %d %d", &s, &n, &m);
    for (int i = 1; i <= s; i++) {
	for (int j = 1; j <= n; j++) {
	    scanf("%d", &arr[j][i]);
	}
    }

    for (int i = 1; i <= n; i++) {
	sort(arr[i] + 1, arr[i] + 1 + s);
	for (int j = 1; j <= s; j++) {
	    group[i][j] = {2 * arr[i][j] + 1, i * j};
	}
    }

    for (int i = 1; i <= n; i++) {
	for (int j = m; j >= 0; j--) {
	    for (int k = 1; k <= s; k++) {
		if (j - group[i][k].first >= 0)
		    dp[j] = max(dp[j], dp[j - group[i][k].first] + group[i][k].second);
	    }
	}
    }

    printf("%d\n", dp[m]);

    return 0;
}
