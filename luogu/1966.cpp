#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 1e5 + 10, mod = 1e8 - 3;
int n;
int arr1[N], arr2[N], arr3[N], order1[N], order2[N], tree[N];

void update(int i) {
    for (; i <= n; i += i & -i)
	tree[i]++;
}

int query(int i) {
    int rst = 0;
    for (; i; i -= i & -i)
	rst += tree[i];
    return rst;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr1[i]);
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr2[i]);

    iota(order1 + 1, order1 + 1 + n, 1);
    iota(order2 + 1, order2 + 1 + n, 1);
    sort(order1 + 1, order1 + 1 + n, [&](int i, int j) {
	return arr1[i] < arr1[j];
    });
    sort(order2 + 1, order2 + 1 + n, [&](int i, int j) {
	return arr2[i] < arr2[j];
    });

    for (int i = 1; i <= n; i++)
	arr3[order1[i]] = order2[i];

    int rst = 0;
    for (int i = 1; i <= n; i++) {
	update(arr3[i]);
	rst = (rst + i - query(arr3[i])) % mod;
    }

    cout << rst << endl;

    return 0;
}
