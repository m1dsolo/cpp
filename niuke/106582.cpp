// 这题好象不支持cpp11
#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

list<pair<int, int> > adj[N];
int n, dis[N];

void dfs(int u, int a, int len) {
    dis[u] = len;
    for (list<pair<int, int> >::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
	if (it->first == a) continue;
	dfs(it->first, u, len + it->second);
    }
}

int main() {
    int m, u, v, w;
    char s[2];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d %s", &u, &v, &w, s);
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
    }
    dfs(1, 0, 0);
    int root, max_val = 0;
    for (int i = 1; i <= n; i++) {
	if (dis[i] > max_val) {
	    max_val = dis[i];
	    root = i;
	}
    }

    dfs(root, 0, 0);
    printf("%d\n", *max_element(dis + 1, dis + 1 + n));

    return 0;
}
