// zkw线段树
// 参考https://www.cnblogs.com/Judge/p/9514862.html

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int n, m, q;	    // (似乎是)n为数组值个数，m为开的空间后，v[0]的起始位置为m + 1
int sum[N << 2], mins[N << 2], maxs[N << 2], add[N << 2];  // 开4倍空间肯定够用, add为标记数组

inline void build(const vector<int> &v){
    n = v.size();
    for (m = 1; m <= n; m <<= 1);   // 保证m > n使得线段树可以容纳下所有叶子节点
    for (int i = 0; i < n; i++)
	sum[m + 1 + i] = mins[m + 1 + i] = maxs[m + 1 + i] = v[i];
    for (int i = m - 1; i; i--) {
	sum[i] = sum[i << 1] + sum[i << 1 | 1];
	mins[i] = min(mins[i << 1], mins[i << 1 | 1]);
	mins[i << 1] -= mins[i], mins[i << 1 | 1] -= mins[i];
	maxs[i] = max(maxs[i << 1], maxs[i << 1 | 1]);
	maxs[i << 1] -= maxs[i], maxs[i << 1 | 1] -= maxs[i];
    }
}

inline void update(int i, int val) {
    i += m, sum[i] += val, maxs[i] += val, mins[i] += val; 
    int tmp;
    for (; i > 1; i >>= 1) {
	sum[i] += val;
	tmp = min(mins[i], mins[i ^ 1]);
	mins[i] -= tmp, mins[i ^ 1] -= tmp, mins[i >> 1] += tmp;
	tmp = max(maxs[i], maxs[i ^ 1]);
	maxs[i] -= tmp, maxs[i ^ 1] -= tmp, maxs[i >> 1] += tmp;
    }
}

inline void update(int l, int r, int val) {
    int tmp = 0, lc = 0, rc = 0, len = 1;
    for (l += m - 1, r += m + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
	if (l & 1 ^ 1) add[l ^ 1] += val, lc += len, maxs[l ^ 1] += val, mins[l ^ 1] += val;
	if (r & 1) add[r ^ 1] += val, rc += len, maxs[r ^ 1] += val, mins[r ^ 1] += val;
	sum[l >> 1] += val * lc, sum[r >> 1] += val * rc;
	tmp = max(maxs[l], maxs[l ^ 1]), maxs[l] -= tmp, maxs[l ^ 1] -= tmp, maxs[l >> 1] += tmp;
	tmp = max(maxs[r], maxs[r ^ 1]), maxs[r] -= tmp, maxs[r ^ 1] -= tmp, maxs[r >> 1] += tmp;
	tmp = min(mins[l], mins[l ^ 1]), mins[l] -= tmp, mins[l ^ 1] -= tmp, mins[l >> 1] += tmp;
	tmp = min(mins[r], mins[r ^ 1]), mins[r] -= tmp, mins[r ^ 1] -= tmp, mins[r >> 1] += tmp;
    }
    // l开始时不需要>>=1?(因为max时需要l,如果只sum，可以>>=1)
    for (lc += rc; l; l >>= 1) {
	sum[l >> 1] += val * lc;
	tmp = max(maxs[l], maxs[l ^ 1]), maxs[l] -= tmp, maxs[l ^ 1] -= tmp, maxs[l >> 1] += tmp;
	tmp = min(mins[l], mins[l ^ 1]), mins[l] -= tmp, mins[l ^ 1] -= tmp, mins[l >> 1] += tmp;
    }
}

inline int query_val(int i) {
    int rst = 0;
    for (i += m; i; i >>= 1)
	rst += mins[i];	    // 或者maxs[i]
    return rst;
}

inline int query_sum(int l, int r) {
    int lc = 0, rc = 0, len = 1, rst = 0;
    for (l += m - 1, r += m + 1; l ^ r ^ 1; l >>= 1, r >>= 1, len <<= 1) {
	if (l & 1 ^ 1) rst += sum[l ^ 1] + len * add[l ^ 1], lc += len;
	if (r & 1) rst += sum[r ^ 1] + len * add[r ^ 1], rc += len;
	rst += add[l >> 1] * lc + add[r >> 1] * rc;
    }
    for (lc += rc, l >>= 1; l; l >>= 1)
	rst += add[l] * lc;
    return rst;
}

// 注意l加m而不是m - 1
inline int query_min(int l, int r) {
    if (l == r) return query_val(l);
    int lval = 0, rval = 0;
    for (l += m, r += m; l ^ r ^ 1; l >>= 1, r >>= 1) {
	lval += mins[l], rval += mins[r];
	if (l & 1 ^ 1) lval = min(lval, mins[l ^ 1]);
	if (r & 1) rval = min(rval, mins[r ^ 1]);
    }
    int rst = min(lval, rval);
    for (l >>= 1; l; l >>= 1)
	rst += mins[l];

    return rst;
}

inline int query_max(int l, int r) {
    if (l == r) return query_val(l);
    int lval = 0, rval = 0;
    for (l += m, r += m; l ^ r ^ 1; l >>= 1, r >>= 1) {
	lval += maxs[l], rval += maxs[r];
	if (l & 1 ^ 1) lval = max(lval, maxs[l ^ 1]);
	if (r & 1) rval = max(rval, maxs[r ^ 1]);
    }
    int rst = max(lval, rval);
    for (l >>= 1; l; l >>= 1)
	rst = max(rst, maxs[l]);
    return rst;
}

int main() {
    build(vector<int>{1, 5, 4, 2, 3});

    for (int i = 1; i <= n; i++) {
	cout << query_sum(1, i) << " ";
    }
    cout << endl;

    return 0;
}
