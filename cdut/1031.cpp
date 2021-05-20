#include <iostream>

using namespace std;
using ll = long long;

const int mod = 19260817;

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
    return (a * qpow(b, mod - 2)) % mod;
}

ll C(ll n, ll m) {
    ll x = 1, y = 1;
    for (int i = n; i > n - m; i--)
	x = (x * i) % mod;
    for (int i = m; i; i--)
	y = (y * i) % mod;
    return (x * qpow(y, mod - 2)) % mod;
}

int main() {
    int n;
    cin >> n;
    ll x, y = 3 * n + 1, rst = 0;
    for (int i = 0; i <= n; i++) {
	x = C(n, i);
	rst = (rst + (((n & 1) ^ (i & 1)) ? -get_mod(x, y) : get_mod(x, y))) % mod;
	y -= 2;
    }

    cout << (rst + mod) % mod << endl;

    return 0;
}
