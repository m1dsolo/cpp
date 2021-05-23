#include <iostream>

using namespace std;

const int N = 2e4;

int n, tree[N];

int dfs(int i) {
    if (tree[i] <= 1) return 1;
    return dfs(i << 1) + dfs(i << 1 | 1) + 1;
}

int main() {
    int k, a;
    scanf("%d %d", &n, &k);
    while (k--) {
	scanf("%d", &a);
	tree[n - 1 + a] = 1;
    }

    for (int i = n - 1; i; i--)
	tree[i] = tree[i << 1] + tree[i << 1 | 1];

    printf("%d\n", dfs(1));

    return 0;
}
