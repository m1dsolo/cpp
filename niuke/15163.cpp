#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int n, tree[N];
void update(int i) {
    for (; i <= n + 5; i += i & -i)
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
    int a;
    ll rst = 0;
    for (int i = 0; i < n; i++) {
	scanf("%d", &a);
	update(a + 5);
	rst += query(n + 5) - query(a + 5);
    }

    printf("%lld\n", rst);

    return 0;
}
