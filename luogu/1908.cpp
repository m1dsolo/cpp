// 树状数组求逆序对，离散化+遍历(update() and rst += i -query())
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 5e5 + 10;
int n, arr[N], order[N], ranks[N], tree[N];

inline void update(int i) {
    for (; i <= n; i += i & -i)
	tree[i]++;
}

inline int query(int i) {
    int rst = 0;
    for (; i; i -= i & -i)
	rst += tree[i];
    return rst;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);
    iota(order + 1, order + 1 + n, 1);
    sort(order + 1, order + 1 + n, [&](int i, int j) {
	return arr[i] < arr[j];
    });

    ranks[order[1]] = 1;
    for (int i = 2; i <= n; i++)
	ranks[order[i]] = ranks[order[i - 1]] + (arr[order[i]] != arr[order[i - 1]]);

    long long rst = 0;
    for (int i = 1; i <= n; i++) {
	update(ranks[i]);
	rst += i - query(ranks[i]);
    }

    cout << rst << endl;

    return 0;
}
