#include <iostream>

using namespace std;

int arr[110], dp[(int)1e4 + 10];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
	for (int j = m; j >= arr[i]; j--)
	    dp[j] += dp[j - arr[i]];
    }

    printf("%d\n", dp[m]);

    return 0;
}
