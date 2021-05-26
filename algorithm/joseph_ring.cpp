#include <iostream>

using namespace std;
using ll = long long;


//int joseph_ring(int n, int k) {
    //int rst = 0;
    //for (int i = 2; i <= n; i++)
	//rst = (rst + k) % i;
    //return rst + 1;
//}

// 当k远小于n时，复杂度为O(k)
ll joseph_ring(ll n, ll k) {
    ll rst = 0;
    for (ll i = 2; i <= n; i++) {
	ll num = min((i - 1 - rst) / k, n - i);
	i += num;
	rst = (rst + k * (num + 1)) % i;
    }
    return rst + 1;
}
int main() {
    cout << joseph_ring(10000, 2) << endl;

    return 0;
}
