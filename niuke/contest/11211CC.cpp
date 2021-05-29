#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

char s[N], dp[N], pos[N];
int size, arr[N];

int main() {
    int n;
    scanf("%d%s", &n, s);

    dp[size++] = s[0];
    for (int i = 1; i < n; i++) {
	if (s[i] >= dp[size - 1]) {
	    pos[i] = size;
	    dp[size++] = s[i];
	}
	else {
	    int index = upper_bound(dp, dp + size, s[i]) - dp;
	    pos[i] = index;
	    dp[index] = s[i];
	}
    }

    int j = size - 1, rst = 0;
    for (int i = n - 1; i >= 0; i--) {
	if (j < 0) break;
	if (pos[i] == j) {
	    arr[j] = i;
	    dp[j--] = s[i];
	}
    }

    j = 0;
    for (int i = 0; i < n; i++) {
	if (j + 1 < size && arr[j + 1] == i) j++;
	rst += abs(s[i] - dp[j]);
    }

    printf("%d\n", rst);

    return 0;
}
