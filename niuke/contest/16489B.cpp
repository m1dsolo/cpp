#include <iostream>

using namespace std;
using ll = long long;

const int mod = 998244353;

ll qpow(ll a, ll n) {
    ll rst = 1;
    while (n) {
	if (n & 1) rst = (rst * a) % mod;
	n >>= 1;
	a = (a * a) % mod;
    }
    return rst;
}

ll get_mod(ll a, ll b) {
    return a * qpow(b, mod - 2) % mod;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	printf("%d\n", get_mod((100 - n) * (100 - n), 10000));
    }

    return 0;
}
