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

// 费马小定理: a ** p % p == a % p	(p需要是素数)
// 由费马小定理：a / b % p --> a * (b ** -1) % p --> a * (b ** (p - 2)) % p
ll get_mod(ll a, ll b) {
    return a * qpow(b, mod - 2) % mod;
}

int main() {
    cout << get_mod(1, 4) % mod << endl;

    return 0;
}
