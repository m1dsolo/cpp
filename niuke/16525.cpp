#include <iostream>

using namespace std;
using ll = long long;

ll qpow(ll a, ll n, int mod) {
    ll rst = 1;
    while (n) {
	if (n & 1) rst = rst * a % mod;
	n >>= 1;
	a = a * a % mod;
    }
    return rst;
}

int main() {
    int n, m, k, x;
    scanf("%d %d %d %d", &n, &m, &k, &x);
    printf("%d\n", ((ll)m * qpow(10, k, n) % n + x) % n);

    return 0;
}
