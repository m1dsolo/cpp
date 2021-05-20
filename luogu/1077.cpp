#include <iostream>

using namespace std;

const int mod = 1e6 + 7;

int n, m;
int arr[101];
int memo[101][101];

int dfs(int index, int sum) {
    if (index == n - 1)
	return memo[index][sum] = sum <= arr[index];
    for (int i = 0; i <= arr[index]; i++) {
	if (sum - i < 0) break;
	memo[index][sum] = (memo[index][sum] + (memo[index + 1][sum - i] ? memo[index + 1][sum - i] : dfs(index + 1, sum - i))) % mod;
    }
    return memo[index][sum];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
	cin >> arr[i];
    }
    cout << dfs(0, m) << endl;

    return 0;
}
