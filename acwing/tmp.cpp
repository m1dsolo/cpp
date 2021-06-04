#include <iostream>
#include <list>

using namespace std;

const int N = 4e4 + 10;

int ps[N][25], ds[N], lg[N];

list<int> adj[N];

void dfs(int u, int p) {
    ps[u][0] = p, ds[u] = ds[p] + 1;
    for (int i = 1; i <= lg[ds[u]]; i++)
        ps[u][i] = ps[ps[u][i - 1]][i - 1];
    for (int v : adj[u])
        if (v != p) dfs(v, u);
}

int lca(int a, int b) {
    if (ds[a] < ds[b]) swap(a, b);
    while (ds[a] > ds[b])
        a = ps[a][lg[ds[b] - ds[a]] - 1];
    if (a == b) return a;
    for (int i = lg[ds[a]] - 1; i >= 0; i--)
        if (ps[a][i] != ps[b][i])
            a = ps[a][i], b = ps[b][i];
    return ps[a][0];
}

int main() {
    int n, root, u, v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v, &u);
        if (u == -1) { root = v; continue; }
        adj[u].emplace_back(v);
    }
    for (int i = 1; i < N; i++)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    dfs(root, 0);
        
    int m, x, y;
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &x, &y);
        int z = lca(x, y);
        cout << x << " " << y << " " << z << endl;
        printf("%d\n", z == x ? 1 : (z == y ? 2 : 0));
    }
    
    return 0;
}
