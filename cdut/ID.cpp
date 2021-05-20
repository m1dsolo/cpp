#include <iostream>
#include <cstring>

using namespace std;

const int N = 3e3 + 10;
double dp[N][N];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
	int h1, h2, r, t;
	double p;
	scanf("%d %d", &h1, &h2);
	scanf("%d %d %lf", &r, &t, &p);

	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= h1; i++) {
	    for (int j = 1; j <= h2; j++) {
		dp[i][j] = 1;
		if (j - r > 0) dp[i][j] += dp[i][j - r] * p;
		if (i - t > 0) dp[i][j] += dp[i - t][j] * (1 - p);
	    }
	}
	printf("%.7lf %d\n", dp[h1][h2], min(h1 / t + (bool)(h1 % t), h2 / r + (bool)(h2 % r)));
    }

    return 0;
}
