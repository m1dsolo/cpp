#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int sum[N << 2], add[N << 2];

int n, m;

void update(int l, int r, int val) {
    int lc = 0, rc = 0, len = 1;
    for (l += m - 1, r += m + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
	if (l & 1 ^ 1) add[l ^ 1] += val, lc += len;
	if (r & 1) add[r ^ 1] += val, rc += len;
	sum[l >> 1] += val * lc, sum[r >> 1] += val * rc;
    }
    for (lc += rc, l >>= 1; l; l >>= 1)
	sum[l] += val * lc;
}

int query(int l, int r) {
    int lc = 0, rc = 0, len = 1, rst = 0;
    for (l += m - 1, r += m + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
	if (l & 1 ^ 1) rst += sum[l ^ 1] + len * add[l ^ 1], lc += len;
	if (r & 1) rst += sum[r ^ 1] + len * add[r ^ 1], rc += len;
	rst += add[l >> 1] * lc + add[r >> 1] * rc;
    }
    for (lc += rc, l >>= 1; l; l >>= 1)
	rst += add[l] * lc;
    return rst % 2;
}
 
int main() {
    int q, a, b, c;
    scanf("%d %d", &n, &q);
    for (m = 1; m <= n; m <<= 1);
    for (int i = 0; i < q; i++) {
	scanf("%d %d", &a, &b);
	if (a == 1) {
	    scanf("%d", &c);
	    update(b, c, 1);
	}
	else
	    cout << query(b, b) << endl;
    }

    return 0;
}
