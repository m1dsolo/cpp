#include <iostream>
#include <list>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int arr[N];
ll rst = -1e18;
list<int> adj[N];

ll dfs(int u, int p) {
    ll val = arr[u];
    for (int v : adj[u]) {
	if (v == p) continue;
	val += max(0ll, dfs(v, u));
    }
    rst = max(rst, val);
    return val;
}

int main() {
    int n, u, v;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);
    for (int i = 0; i < n - 1; i++) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
    }
    dfs(1, 0);

    printf("%lld\n", rst);

    return 0;
}
