#include <iostream>

using namespace std;
using ll = long long;
using L = initializer_list<int>;
using LL = initializer_list<initializer_list<int>>;

const int mod = 1e9 + 9;

class matrix {
public:
    ll arr[4][4] = {0};
    matrix() {
	for (int i = 0; i < 4; i++)
	    arr[i][i] = 1;
    }
    matrix(LL list) {
	int i = 0, j = 0;
	for (const L &l : list) {
	    for (int a : l) {
		arr[i][j++] = a;
	    }
	    i++;
	    j = 0;
	}
    }
    void operator*=(const matrix &m) {
	ll tmp[4][4] = {0};
	for (int i = 0; i < 4; i++) {
	    for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4; k++)
		    tmp[i][j] = (tmp[i][j] + arr[i][k] * m.arr[k][j]) % mod;
	    }
	}	
	for (int i = 0; i < 4; i++) {
	    for (int j = 0; j < 4; j++)
		arr[i][j] = tmp[i][j];
	}
    }
};

matrix qpow(matrix m, ll n) {
    matrix rst;
    while (n) {
	if (n & 1) rst *= m;
	n >>= 1;
	m *= m;
    }
    return rst;
}

int main() {
    ll n;
    matrix base {{2, 1, 2, 1}, {0, 1, 2, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}};
    while (scanf("%lld", &n) != EOF) {
	matrix rst = qpow(base, n);
	printf("%d\n", rst.arr[0][3]);
    }

    return 0;
}
