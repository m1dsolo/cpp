#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int arr[N], dp[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);

    int size = 1;
    dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
	if (arr[i] > dp[size - 1])
	    dp[size++] = arr[i];
	else
	    *lower_bound(dp, dp + size, arr[i]) = arr[i];
    }

    printf("%d\n", size);

    return 0;
}
