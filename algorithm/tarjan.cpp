// 参考https://byvoid.com/zhs/blog/scc-tarjan/
#include <iostream>
#include <list>

using namespace std;

int n, m, index, cnt, top;

int dfn[5], low[5], stack[5], belong[5], maxs[5];
bool visited[5];

list<int> adj[5];

// O(n + m) n为顶点，m为边
void tarjan(int u) {
    visited[u] = true;
    stack[++top] = u;
    dfn[u] = low[u] = ++index;
    for (int v : adj[u]) {
	if (!dfn[v]) {
	    tarjan(v);
	    low[u] = min(low[u], low[v]);
	}
	else if (visited[v])
	    low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {	    // 如果u和其子树能构成一个连通分量
	cnt++;
	while (int i = stack[top--]) {
	    visited[i] = false;
	    belong[u] = cnt;
	    maxs[cnt] = max(maxs[cnt], i);
	    if (u == i) break;
	}
    }
}

int main() {
    adj[1].emplace_back(2);
    adj[2].emplace_back(4);
    adj[4].emplace_back(3);

    // rst is {4 4 3 4}

    tarjan(1);
    int n = 4;
    for (int i = 1; i <= n; i++) {
	cout << belong[i] << ' ';
    }
    cout << endl;

    return 0;
}
