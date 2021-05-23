#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[110];
bool dp[25010] = {true};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	    scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int max_val = arr[n - 1];
	memset(dp + 1, 0, max_val);
	int rst = 0;
	for (int i = 0; i < n; i++) {
	    if (dp[arr[i]]) continue;
	    rst++;
	    for (int j = arr[i]; j <= max_val; j++) {
		if (dp[j - arr[i]])
		    dp[j] = true;
	    }
	}
	printf("%d\n", rst);
    }

    return 0;
}
