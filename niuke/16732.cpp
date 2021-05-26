#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e3 + 10, mod = 1e9 + 7;
ll f[N] = {1};

ll qpow(ll a, ll n) {
    ll rst = 1;
    while (n) {
	if (n & 1) rst = (rst * a) % mod;
	n >>= 1;
	a = (a * a) % mod;
    }
    return rst;
}

ll C(ll n, ll m) {
    return f[n] % mod * qpow(f[n - m], mod - 2) % mod * qpow(f[m], mod - 2) % mod;
}

int main() {
    int n;
    scanf("%d", &n);

    ll rst = 0;
    for (int i = 1; i <= n; i++)
	f[i] = f[i - 1] * i % mod;
    for (int i = 0; (i << 1) <= n - 1; i += 2)
	rst = (rst + C(n - 1, i) * C(n - i - 1, i)) % mod;

    printf("%lld\n", rst);

    return 0;
}
