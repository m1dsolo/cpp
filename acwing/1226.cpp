#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int arr[N];
bool dp[N * N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n, g = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
	g = gcd(g, arr[i]);
    }

    memset(dp, false, sizeof(dp));
    dp[0] = true;
    if (g != 1)
	printf("INF\n");
    else {
	for (int i = 0; i < n; i++) {
	    for (int j = arr[i]; j <= 1e4; j++)
		if (dp[j - arr[i]]) dp[j] = true;
	}
	int rst = 0;
	for (int i = 1; i <= 1e4; i++)
	    if (!dp[i]) rst++;
	printf("%d\n", rst);
    }

    return 0;
}
