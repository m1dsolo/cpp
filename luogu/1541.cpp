#include <iostream>

using namespace std;

const int N = 360;
int arr[N];
int cards[5];
int dp[45][45][45][45];

int main() {
    int n, m, a;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) 
	scanf("%d", &arr[i]);
    for (int i = 0; i < m; i++) {
	scanf("%d", &a);
	cards[a]++;
    }

    dp[0][0][0][0] = arr[0];
    for (int i1 = 0; i1 <= cards[1]; i1++) {
	for (int i2 = 0; i2 <= cards[2]; i2++) {
	    for (int i3 = 0; i3 <= cards[3]; i3++) {
		for (int i4 = 0; i4 <= cards[4]; i4++) {
		    int d = i1 + i2 * 2 + i3 * 3 + i4 * 4;
		    if (i1) dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], dp[i1 - 1][i2][i3][i4] + arr[d]);
		    if (i2) dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], dp[i1][i2 - 1][i3][i4] + arr[d]);
		    if (i3) dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], dp[i1][i2][i3 - 1][i4] + arr[d]);
		    if (i4) dp[i1][i2][i3][i4] = max(dp[i1][i2][i3][i4], dp[i1][i2][i3][i4 - 1] + arr[d]);
		}
	    }
	}
    }

    printf("%d\n", dp[cards[1]][cards[2]][cards[3]][cards[4]]);

    return 0;
}
