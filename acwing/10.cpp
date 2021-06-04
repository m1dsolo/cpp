// https://www.acwing.com/solution/content/8316/
#include <iostream>
#include <vector>

using namespace std;

const int N = 110;

struct item {
    int v;
    int w;
} arr[N];

int m, dp[N][N];	// dp[i][j]为选择了i子树的物品，容量不超过j所获得的最大价值
vector<int> adj[N];

void dfs(int u) {
    for (int j = arr[u].v; j <= m; j++) dp[u][j] = arr[u].w;
    for (int v : adj[u]) {
	dfs(v);
	for (int j = m; j >= arr[u].v; j--) {
	    for (int k = 0; k <= j - arr[u].v; k++)	    // 分给子树v的背包空间
	    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
	}
    }
}

int main() {
    int n, p, root;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
	scanf("%d %d %d", &arr[i].v, &arr[i].w, &p);
	if (p == -1) root = i;
	else adj[p].emplace_back(i);
    }
    dfs(root);

    printf("%d\n", dp[root][m]);

    return 0;
}
