#include <iostream>
#include <list>
#include <queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int N = 1e5 + 10;
int ind[N];
list<P> adj[N];
double weights[N] = {0, 1}, dp[N];

// 说白了就是求每条边的权重w，然后乘len，累加起来就是总期望
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int u, v, w;
    while (m--) {
	scanf("%d %d %d", &u, &v, &w);
	adj[u].push_back({v, w});
	ind[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
	if (!ind[i])
	    q.emplace(i);
    }

    double rst = 0;
    while (int size = q.size()) {
	while (size--) {
	    int u = q.front(); q.pop();
	    double w = weights[u] / adj[u].size();
	    rst += dp[u];   // 累加，不能沿着dp往下传，导致结果增大
	    for (P p : adj[u]) {
		int v = p.first, len = p.second;
		weights[v] += w;
		dp[v] += w * len;
		if (!--ind[v])
		    q.emplace(v);
	    }
	}
    }

    printf("%.2lf\n", rst);

    return 0;
}
