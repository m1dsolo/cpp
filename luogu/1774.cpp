#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;
int n, tree[N], order[N], ranks[N];
long long arr[N];

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
    int a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
	scanf("%lld", &arr[i]);

    iota(order + 1, order + 1 + n, 1);
    sort(order + 1, order + 1 + n, [&](int i, int j) {
	return arr[i] < arr[j];
    });
    ranks[order[1]] = 1;
    for (int i = 2; i <= n; i++)
	ranks[order[i]] = ranks[order[i - 1]] + (arr[order[i - 1]] != arr[order[i]]);

    long long rst = 0;
    for (int i = 1; i <= n; i++) {
	update(ranks[i]);
	rst += i - query(ranks[i]);
    }

    cout << rst << endl;

    return 0;
}
