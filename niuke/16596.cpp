// 二项式定理
#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e3 + 10, mod = 1e4 + 7;

ll qpow(ll a, int n) {
    ll rst = 1;
    while (n) {
	if (n & 1) rst = rst * a % mod;
	n >>= 1;
	a = a * a % mod;
    }
    return rst;
}

ll C(int n, int m) {
    ll x = 1, y = 1;
    for (int i = n; i > n - m; i--)
	x = x * i % mod;
    for (int i = m; i; i--)
	y = y * i % mod;
    return x * qpow(y, mod - 2) % mod;
}

int main() {
    int a, b, k, n, m;
    scanf("%d %d %d %d %d", &a, &b, &k, &n, &m);

    printf("%lld\n", C(k, n) * qpow(a % mod, n) % mod * qpow(b % mod, m));

    return 0;
}
