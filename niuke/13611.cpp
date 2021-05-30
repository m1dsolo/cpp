#include <iostream>

using namespace std;
using ll = long long;

const int N = 300, mod = 1e9 + 7;
int f[N + 10] = {1};

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
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= N; i++)
	f[i] = (ll)f[i - 1] * i % mod;
    int rst = 0;
    for (int i = 1; i <= min(n, k); i++)  // 分的块数
	rst = (rst + (ll)C(k, i) * C(n - 1, i - 1) % mod * f[i] % mod) % mod;

    printf("%d\n", rst);

    return 0;
}
