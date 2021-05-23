#include <iostream>

using namespace std;

int arr[40];
bool dp[(int)2e4 + 10];

int main() {
    int v, n;
    scanf("%d", &v);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);

    int rst = 0;
    dp[0] = true;
    for (int i = 0; i < n; i++) {
	for (int j = v; j >= arr[i]; j--)
	    if (dp[j - arr[i]]) {
		dp[j] = true;
		rst = max(rst, j);
	    }
    }

    printf("%d\n", v - rst);

    return 0;
}
