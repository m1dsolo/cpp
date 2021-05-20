#include <iostream>
#include <list>
#include <queue>

using namespace std;

const int N = 1e4 + 10;

list<int> adj[N];
int arr[N], ind[N], dp[N];

int main() {
    int n;
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i <= n; i++) {
	scanf("%d", &v);
	scanf("%d", &arr[v]);
	while (1) {
	    scanf("%d", &u);
	    if (!u) break;
	    adj[u].emplace_back(v);
	    ind[v]++;
	}
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
	if (!ind[i]) {
	    dp[i] = arr[i];
	    q.emplace(i);
	}
    }

    int rst = 0;
    while (int size = q.size()) {
	while (size--) {
	    int u = q.front(); q.pop();
	    for (int v : adj[u]) {
		dp[v] = max(dp[v], dp[u] + arr[v]);	// 保证需求都满足
		rst = max(rst, dp[v]);			// max才能保证所有任务都做完
		if (!--ind[v])
		    q.emplace(v);
	    }
	}
    }

    printf("%d\n", rst);

    return 0;
}
