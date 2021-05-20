#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

long long qpow(long long a, int n) {
    long long rst = 1;
    while (n) {
	if (n & 1) rst = (rst * a) % mod;
	n >>= 1;
	a = (a * a) % mod;
    }
    return rst;
}

int main() {
    //int k;
    //cin >> k;
    //string s;
    //cin >> s;

    int k = 3;
    string s = "125390";
    int n = s.length();
    long long rst = 0;
    long long a = 1;
    for (char c : s) {
	if (c == '0' || c == '5')
	    rst = (rst + a) % mod;
	a = (a * 2) % mod;
    }

    long long inv = qpow(qpow(2, n) - 1, mod - 2);
    long long tmp = ((qpow(2, n * k) - 1) * inv) % mod;

    cout << (rst * tmp) % mod << endl;

    return 0;
}
