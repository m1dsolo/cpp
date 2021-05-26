#include <iostream>
#include <list>

using namespace std;

const int N = 5e4 + 10;

list<int> adj[N];

int n, num[N], len;
int init(int u, int p, int l) {
    num[u] = 1;
    len += l;
    for (int v : adj[u]) {
	if (v != p) num[u] += init(v, u, l + 1);
    }
    return num[u];
}

int rst, min_len = 2e9;
void dfs(int u, int p, int l) {
    if (l < min_len || (l == min_len && u < rst)) {
	min_len = l;
	rst = u;
    }
    for (int v : adj[u]) {
	if (v != p) dfs(v, u, l + n - 2 * num[v]);
    }
}

int main() {
    int a, b;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
	scanf("%d %d", &a, &b);
	adj[a].emplace_back(b);
	adj[b].emplace_back(a);
    }

    init(1, 0, 0);
    dfs(1, 0, len);

    printf("%d %d\n", rst, min_len);

    return 0;
}
