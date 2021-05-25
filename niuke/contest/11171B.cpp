// TLE(trie做法)(如果优化比如memset啥的应该可能过，但是这题应该用区间dp)
#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

const int N = 5e3 + 10;

ll arr[N], dp[N][N];
int nodes[N * 40][2], size;

void update(ll a) {
    int p = 0;
    for (int i = 40; i >= 0; i--) {
	bool cur = a >> i & 1;
	if (!nodes[p][cur])
	    nodes[p][cur] = ++size;
	p = nodes[p][cur];
    }
}

ll query(ll a) {
    int p = 0;
    ll rst = 0;
    for (int i = 40; i >= 0; i--) {
	bool cur = a >> i & 1;
	rst <<= 1;
	if (nodes[p][cur ^ 1]) {
	    rst |= 1;
	    p = nodes[p][cur ^ 1];
	}
	else
	    p = nodes[p][cur];
    }
    return rst;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
	scanf("%lld", &arr[i]);

    for (int i = 1; i <= n; i++) {
	memset(nodes, 0, sizeof(nodes));
	size = 0;
	for (int j = i; j <= n; j++) {
	    update(arr[j]);
	    dp[i][j] = max(dp[i][j - 1], query(arr[j]));
	}
    }

    int l, r;
    while (m--) {
	scanf("%d %d", &l, &r);
	printf("%lld\n", dp[l][r]);
    }

    return 0;
}
