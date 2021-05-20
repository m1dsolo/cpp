// https://www.cnblogs.com/linyujun/p/5194184.html三种方法求逆元，第三种方法可以在O(n)时间求出n个数的inv
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

// a * x === 1 (mod b),其中a与b互斥，那么x就是a的逆元(数论倒数)
ll inv(ll a) {
    return qpow(a, mod - 2);
}

int main() {
    for (int i = 1; i <= 10; i++)
	cout << inv(i) << endl;

    return 0;
}
