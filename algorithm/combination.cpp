#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int N = 100, mod = 1e9 + 9;
ll f[N] = {1};

// O(logn)
// fast get pow(a, n);
ll qpow(ll a, ll n) {
    ll rst = 1;
    while (n) {
	if (n & 1) rst = rst * a % mod;
	n >>= 1;
	a = a * a % mod;
    }
    return rst;
}

// C(n, m), n is below
// O((n + m)*logn) (n + m可以用阶乘表)
ll C(ll n, ll m) {
    //return f[n] * qpow(f[n - m], mod - 2) % mod * qpow(f[m], mod - 2) % mod;
    ll x = 1, y = 1;
    for (int i = n; i > n - m; i--)
	x = x * i % mod;
    for (int i = m; i; i--)
	y = y * i % mod;
    return x * qpow(y, mod - 2) % mod;
}

// 补充：递推公式C(n, m) = C(n - 1, m - 1) + C(n - 1, m)，这个公式可以用来O(n * m)求C(0, 0) ~ C(n, m)所有C
vector<vector<ll>> Cs(ll n, ll m) {
    vector<vector<ll>> rst(n + 1, vector<ll>(m + 1));
    rst[0][0] = 1;
    for (int i = 1; i <= n; i++) {
	rst[i][0] = 1;
	for (int j = 1; j <= min(m, (ll)i); j++) {
	    rst[i][j] = (rst[i - 1][j - 1] + rst[i - 1][j]) % mod;
	}
    }
    return rst;
}


int main() {
    // 阶乘预处理
    //for (int i = 1; i < N; i++)
	//f[i] = f[i - 1] * i % mod;
    //cout << C(7, 2) << endl;

    vector<vector<ll>> rst = Cs(100, 50);

    cout << rst[100][50] << endl;

    return 0;
}
