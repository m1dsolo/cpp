#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int cnt, dp[(int)4e4 + 10];
pair<int, int> arr[N];

int main() {
    int n, m, v, w, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
	scanf("%d %d %d", &v, &w, &c);
	for (int j = 1; j <= c; j <<= 1) {
	    arr[++cnt] = {v * j, w * j};
	    c -= j;
	}
	if (c) 
	    arr[++cnt] = {v * c, w * c};
    }

    for (int i = 1; i <= cnt; i++) {
	for (int j = m; j >= arr[i].second; j--) {
	    dp[j] = max(dp[j], dp[j - arr[i].second] + arr[i].first);
	}
    }

    printf("%d\n", dp[m]);

    return 0;
}
