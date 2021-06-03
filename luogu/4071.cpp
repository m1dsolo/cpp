#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e6, mod = 1e9 + 7;

ll f[N + 10] = {1}, d[N + 10] = {1, 0};

ll qpow(ll a, ll n) {
    ll rst = 1;
    while (n) {
	if (n & 1) rst = rst * a % mod;
	n >>= 1;
	a = a * a % mod;
    }
    return rst;
}

ll C(ll n, ll m) {
    return f[n] * qpow(f[n - m], mod - 2) % mod * qpow(f[m], mod - 2) % mod;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    for (int i = 1; i <= N; i++)
	f[i] = (f[i - 1] * i) % mod;
    for (int i = 2; i <= N; i++)	// 错排公式
	d[i] = (d[i - 1] + d[i - 2]) * (i - 1) % mod;
    while (t--) {
	scanf("%d %d", &n, &m);
	printf("%lld\n", C(n, m) * d[n - m] % mod);
    }

    return 0;
}
