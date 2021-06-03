#include <iostream>

using namespace std;
using ll = long long;

int mod;

void mul(ll a[3][3], ll b[3][3]) {
    ll c[3][3] = {0};
    for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	    for (int k = 0; k < 3; k++)
		c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
	}
    }
    for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++)
	    a[i][j] = c[i][j];
    }
}

int main() {
    int n;
    scanf("%d %d", &n, &mod);
    ll a[3][3] {{2, 0, -1}, {1, 0, 0}, {0, 1, 0}}, rst[3][3] = {0};
    for (int i = 0; i < 3; i++)
	rst[i][i] = 1;

    if (n < 3)
	printf("1\n");
    else {
	n -= 3;
	while (n) {
	    if (n & 1) mul(rst, a);
	    n >>= 1;
	    mul(a, a);
	}

	printf("%d\n", (((rst[0][0] * 4 + rst[0][1] * 2 + rst[0][2] * 1) % mod) + mod) % mod);
    }

    return 0;
}
