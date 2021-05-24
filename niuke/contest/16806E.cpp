// 匈牙利算法(2个属性与1个物品进行匹配)(好像并查集也可以做)
// https://blog.csdn.net/qq_43857314/article/details/108001573
// 有问题(TLE WA)
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

list<int> adj[10001];
bool visited[N];
int match[N];

bool dfs(int u) {
    for (int v : adj[u]) {
	if (!visited[v]) {
	    visited[v] = true;
	    if (!match[v] || dfs(v)) {
		match[v] = u;
		return true;
	    }
	}
    }
    return false;
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf("%d %d", &a, &b);
	adj[a].emplace_back(i);
	adj[b].emplace_back(i);
    }

    int i = 1;
    for (; i <= n; i++) {	// 取10000应该也行
	memset(visited, false, n);
	if (!dfs(i))
	    break;
    }

    printf("%d\n", i - 1);

    return 0;
}
