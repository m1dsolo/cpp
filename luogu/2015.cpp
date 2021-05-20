#include <iostream>
#include <list>

using namespace std;

int dp[101][101];
list<pair<int, int>> adj[101];

int dfs(int id, int num) {
    if (!id) return 0;
    if (dp[id][num]) return dp[id][num];
    for (int i = 0; i < num; i++) {
	dp[id][num] = max(dp[id][num], max(dfs(nodes[id].left, i) + nodes[id].left_val, dfs(nodes[id].right, num - i - 1) + nodes[id].right_val));
    }
    return dp[id][num];
}

int main() {
    int n, q, a, b, c;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
	scanf("%d %d %d", &a, &b, &c);
	adj[a].push_back({b, c});
	adj[b].push_back({a, c});	
    }

    cout << dfs(1, q) << endl;

    return 0;
}
