// 复杂度O(n^2)太高了
#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

unordered_map<int, int> memo;

inline int get_hash(int n, int level) {
    return n * (1e6 + 10) + level;
}

int dfs(int n, int level) {
    if (!level) return 1;
    int hash = get_hash(n, level);
    if (memo[hash]) return memo[hash];
    memo[hash] = 1;
    int sum = 0;
    for (int i = 0; i <= n; i++)
	sum = (sum + dfs(n - i, level - 1)) % mod;
    return memo[hash] = (((ll)memo[hash] * sum) % mod);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int max_i = n / k, rst = 0;
    for (int i = 1; i <= max_i; i++)
	rst = (rst + dfs(n - i * k, i - 1)) % mod;

    printf("%d\n", rst);

    return 0;
}
