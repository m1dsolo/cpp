#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e4 + 10;

int dp[N];
pair<int, int> arr[110];

int main() {
    int n, h;
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++)
	scanf("%d %d", &arr[i].first, &arr[i].second);

    memset(dp + 1, 127, sizeof(int) * h);
    for (int i = 0; i < n; i++) {
	for (int j = arr[i].first; j < h; j++)
	    dp[j] = min(dp[j], dp[j - arr[i].first] + arr[i].second);
	for (int j = h - arr[i].first; j <= h; j++)
	    dp[h] = min(dp[h], dp[j] + arr[i].second);
    }

    //for (int i = 0; i <= h; i++)
	//cout << i << " " << dp[i] << endl;

    printf("%d\n", dp[h]);

    return 0;
}
