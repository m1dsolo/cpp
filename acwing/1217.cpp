#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

const int N = 1e6 + 10, M = 1e5 + 10;

int n, arr[M], tree[N << 2], sum[M];

void update(int i) {
    for (; i <= N; i += i & -i)
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
    for (int i = 1; i <= n; i++) {
	scanf("%d", &arr[i]);
	arr[i]++;
	update(arr[i]);
	sum[i] += i - query(arr[i]);
    }

    memset(tree, 0, sizeof(tree));
    for (int i = n; i; i--) {
	update(arr[i]);
	sum[i] += query(arr[i] - 1);
    }

    ll rst = 0;
    for (int i = 1; i <= n; i++)
	rst += ((ll)sum[i] + 1) * sum[i] / 2;

    printf("%lld\n", rst);

    return 0;
}
