// https://zhuanlan.zhihu.com/p/103394468

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll qpow(ll a, ll n, ll p) {
    ll rst = 1;
    while (n) {
	if (n & 1) rst = (rst * a) % p;
	n >>= 1;
	a = (a * a) % p;
    }
    return rst;
}

ll inv(ll a, ll p) {
    return qpow(a, p - 2, p);
}

// 用来求同余方程组，例一个数x对3求余为2，对5求余为3，对7求余为2，求最小这个数
// v1为模数数组{3, 5, 7}, v2为余数数组{2, 3, 2},
ll crt(const vector<int> &v1, const vector<int> &v2) {
    ll p = 1, rst = 0, n = v1.size();
    for (int a : v1)
	p *= a;
    for (int i = 0; i < n; i++) {
	ll r = p / v1[i];
	rst = (rst + v2[i] * r * inv(r, v1[i])) % p;
    }
    return rst;
}

int main() {
    cout << crt({3, 5, 7}, {2, 3, 2}) << endl;

    return 0;
}
