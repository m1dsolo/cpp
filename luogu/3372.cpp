#include <iostream>

using namespace std;

const int N = 100010;
int n, m, q;
long long sum[N << 2], add[N << 2];

void update(int l, int r, int val) {
    long long lc = 0, rc = 0, len = 1;
    for (l += m - 1, r += m + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
	if (l & 1 ^ 1) add[l ^ 1] += val, lc += len;
	if (r & 1) add[r ^ 1] += val, rc += len;
	sum[l >> 1] += val * lc, sum[r >> 1] += val * rc;
    }
    for (lc += rc, l >>= 1; l; l >>= 1)
	sum[l] += val * lc;
}

long long query(int l, int r) {
    long long lc = 0, rc = 0, len = 1, rst = 0;
    for (l += m - 1, r += m + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
	if (l & 1 ^ 1) rst += sum[l ^ 1] + len * add[l ^ 1], lc += len;
	if (r & 1) rst += sum[r ^ 1] + len * add[r ^ 1], rc += len;
	rst += add[l >> 1] * lc + add[r >> 1] * rc;
    }
    for (lc += rc, l >>= 1; l; l >>= 1)
	rst += add[l] * lc;
    return rst;
}

int main() {
    scanf("%d %d", &n, &q);
    for (m = 1; m <= n; m <<= 1);
    for (int i = m + 1; i <= m + n; i++)
	scanf("%lld", &sum[i]);
    for (int i = m - 1; i; i--)
	sum[i] = sum[i << 1] + sum[i << 1 | 1];

    int t, l, r, k;
    for (int i = 0; i < q; i++) {
	scanf("%d", &t);
	if (t == 1) {
	    scanf("%d %d %d", &l, &r, &k);
	    update(l, r, k);
	}
	else {
	    scanf("%d %d", &l, &r);
	    printf("%lld\n", query(l, r));
	}
    }

    return 0;
}
