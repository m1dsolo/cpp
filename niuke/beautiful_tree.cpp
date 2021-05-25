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

int main() {
    ios::sync_with_stdio(false);
    int k;
    string s;
    cin >> k >> s;
    int n = s.length();

    ll rst = 0, step = 1;
    for (char c : s) {
	if (c == '0' || c == '5')
	    rst = (rst + step) % mod;
	step = (step << 1) % mod;
    }

    ll inv = qpow(qpow(2, n) - 1, mod - 2);
    ll tmp = ((qpow(2, n * k) - 1) * inv) % mod;

    cout << (rst * tmp) % mod << endl;

    return 0;
}
