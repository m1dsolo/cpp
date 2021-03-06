#include <iostream>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void mul(ll a[6][6], ll b[6][6]) {
    ll c[6][6] = {0};
    for (int i = 0; i < 6; i++) {
	for (int j = 0; j < 6; j++) {
	    for (int k = 0; k < 6; k++)
		c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
	}
    }
    for (int i = 0; i < 6; i++) {
	for (int j = 0; j < 6; j++)
	    a[i][j] = c[i][j];
    }
}

int main() {
    int t;
    ll n;
    scanf("%d", &t);
    while (t--) {
	ll a[6][6] {{1, 1, 1, 1, 1, 1}, {1}, {0, 0, 1, 3, 3, 1}, {0, 0, 0, 1, 2, 1}, {0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 1}}, rst[6][6] = {0};
	for (int i = 0; i < 6; i++) rst[i][i] = 1;
	scanf("%lld", &n);
	n--;
	while (n) {
	    if (n & 1) mul(rst, a);
	    n >>= 1;
	    mul(a, a);
	}
	printf("%d\n", (rst[0][0] + rst[0][2] * 8 + rst[0][3] * 4 + rst[0][4] * 2 + rst[0][5]) % mod);
    }

    return 0;
}
