#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
string strs[N], dp[N];
int pos[N];

int n = 0;

int main() {
    strs[0] += getchar();
    char c;
    while (scanf("%c", &c) != EOF) {
	if (isupper(c)) {
	    strs[++n] += c;
	}
	else if (islower(c))
	    strs[n] += c;
    }

    dp[0] = strs[0];
    int size = 1;
    for (int i = 1; i <= n; i++) {
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

    for (int i = 0; i <= n; i++)
	cout << dp[i] << " ";
    cout << endl;

    int j = size - 1;
    for (int i = n; i >= 0; i--) {
	if (j < 0) break;
	if (pos[i] == j)
	    dp[j--] = strs[i];
    }

    for (int i = 0; i < size; i++)
	cout << dp[i];
    cout << endl;

    return 0;
}
