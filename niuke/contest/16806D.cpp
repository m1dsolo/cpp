// 牛客小白月赛17
// 答案为连通块个数，如果存在奇数环就减1
// https://blog.csdn.net/weixin_42757232/article/details/101019362
#include <iostream>
#include <list>

using namespace std;

const int N = 1e5 + 10;
bool flag = false;

int color[N];
list<int> adj[N];

void dfs(int u, int c) {
    color[u] = c;
    for (int v : adj[u]) {
	if (color[v] == c)
	    flag = true;
	else if (!color[v])
	    dfs(v, 3 - c);
    }
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    while (m--) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
    }

    int rst = 0;
    for (int i = 1; i <= n; i++) {
	if (!color[i]) {
	    rst++;
	    dfs(i, 1);
	}
    }

    printf("%d\n", rst - flag);

    return 0;
}
