// 平方和公式
#include <iostream>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll qpow(ll a, ll n) {
    ll rst = 1;
    while (n) {
	if (n & 1) rst = (rst * a) % mod;
	n >>= 1;
	a = (a * a) % mod;
    }
    return rst;
}

ll inv(ll a) {
    return qpow(a, mod - 2);
}

int main() {
    ll n;
    while (scanf("%lld", &n) != EOF) {
	n %= mod;
	printf("%d\n", n * (n + 1) % mod * (2 * n + 1) % mod * inv(6) % mod);
    }

    return 0;
}
