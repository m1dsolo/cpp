#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

pair<int, int> arr[20];
int dp[N];

int main() {
    int s, n, d;
    scanf("%d %d %d", &s, &n, &d);
    for (int i = 0; i < d; i++) {
	scanf("%d %d", &arr[i].first, &arr[i].second);
	arr[i].first /= 1000;
    }

    for (int k = 0; k < n; k++) {
	int max_j = s / 1000;
	memset(dp, 0, sizeof(int) * (max_j + 1));
	for (int i = 0; i < d; i++) {
	    for (int j = arr[i].first; j <= max_j; j++)
		dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
	}
	s += dp[max_j];
    }

    printf("%d\n", s);

    return 0;
}
