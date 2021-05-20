#include <iostream>

using namespace std;

const int N = 110, mod = 1e6 + 7;

int n, arr[N], memo[N][N];

int dfs(int index, int m) {
    if (index == n - 1)
	return memo[index][m] = m <= arr[index];
    for (int i = 0; i <= min(m, arr[index]); i++)
	memo[index][m] = (memo[index][m] + (memo[index + 1][m - i] ? memo[index + 1][m - i] : dfs(index + 1, m - i))) % mod;
    return memo[index][m];
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);

    printf("%d\n", dfs(0, m));

    return 0;
}
