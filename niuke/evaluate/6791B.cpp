#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

unordered_map<ll, ll> memo;
int p, q;

ll dfs(ll n) {
    if (!n) return 1;
    return memo[n] ? memo[n] : memo[n] = dfs(n / p) + dfs(n / q);
}

int main() {
    ll n;
    scanf("%lld %d %d", &n, &p, &q);

    printf("%lld\n", dfs(n));

    return 0;
}
