#include <iostream>

using namespace std;

const int N = 1e6 + 10;

string strs[N], dp[N];
int pos[N];

int main() {
    char c;
    int n = 0;
    strs[0] += getchar();
    while (scanf("%c", &c) != EOF) {
	if (islower(c))
	    strs[n] += c;
	else if (isupper(c))
	    strs[++n] = c;
    }

    dp[0] = strs[0];
    int size = 1;
    for (int i = 0; i <= n; i++) {
	if (strs[i] > dp[size - 1]) {
	    pos[i] = size;
	    dp[size++] = strs[i];
	}
	else {
	    int index = lower_bound(dp, dp + size, strs[i]) - dp;
	    pos[i] = index;
	    dp[index] = strs[i];
	}
    }

    size--;
    for (int i = n; i >= 0; i--) {
	if (size < 0) break;
	if (pos[i] == size) {
	    dp[size--] = strs[i];
	}
    }

    for (int i = 0; i <= n; i++)
	printf("%s", dp[i].c_str());
    printf("\n");

    return 0;
}
