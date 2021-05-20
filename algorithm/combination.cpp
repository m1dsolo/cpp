#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 9;

// O(logn)
// fast get pow(a, n);
long long fast_pow(long long a, long long n) {
    long long rst = 1;
    while (n) {
	if (n & 1) rst = rst * a % mod;
	n >>= 1;
	a = a * a % mod;
    }
    return rst;
}

// C(n, m), n is below
// O((n + m)*logn) (n + m可以用阶乘表)
long long C(long long n, long long m) {
    long long x = 1, y = 1;
    for (int i = n; i > n - m; i--)
	x = x * i % mod;
    for (int i = m; i; i--)
	y = y * i % mod;
    return x * fast_pow(y, mod - 2) % mod;
}

// 补充：递推公式C(n, m) = C(n - 1, m - 1) + C(n, m - 1)，这个公式可以用来O(n * m)求C(0, 0) ~ C(n, m)所有C
vector<vector<long long>> Cs(long long n, long long m) {
    vector<vector<long long>> rst(n + 1, vector<long long>(m + 1));
    rst[0][0] = rst[1][0] = rst[1][1] = 1;
    for (int i = 2; i <= n; i++) {
	rst[i][0] = 1;
	for (int j = 1; j <= m; j++) {
	    rst[i][j] = (rst[i - 1][j - 1] + rst[i - 1][j]) % mod;
	}
    }
    return rst;
}


int main() {
    cout << C(100, 50) << endl;

    vector<vector<long long>> rst = Cs(100, 50);

    cout << rst[100][50] << endl;

    return 0;
}
