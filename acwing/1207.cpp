#include <iostream>
#include <list>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

struct path {
    int v;
    int w;
};

int dis[N];
list<path> adj[N];

void dfs(int u, int p, int len) {
    dis[u] = len;
    for (path pa : adj[u])
	if (pa.v != p) dfs(pa.v, u, len + pa.w);
}

int main() {
    int n, u, v, w;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
	scanf("%d %d %d", &u, &v, &w);
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
    }


    dfs(1, 0, 0);
    int max_dis = 0, root = 1;
    for (int u = 2; u <= n; u++) {
	if (dis[u] > max_dis) {
	    max_dis = dis[u];
	    root = u;
	}
    }

    memset(dis, 0, sizeof(dis));
    dfs(root, 0, 0);

    ll max_val = *max_element(dis + 1, dis + 1 + n);
    printf("%lld\n", max_val * 10 + (1 + max_val) * max_val / 2);

    return 0;
}
