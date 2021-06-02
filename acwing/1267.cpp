#include <iostream>

using namespace std;

const int N = 32010;

int n, tree[N << 2], rst[N];

void update(int i) {
    for (; i <= N; i += i & -i)		// 注意范围
	tree[i]++;
}

int query(int i) {
    int rst = 0;
    for (; i; i -= i & -i)
	rst += tree[i];
    return rst;
}

int main() {
    int x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d %d", &x, &y);
	rst[query(x + 1)]++;
	update(x + 1);
    }

    for (int i = 0; i < n; i++)
	printf("%d\n", rst[i]);

    return 0;
}
