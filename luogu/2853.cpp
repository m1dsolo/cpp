#include <iostream>
#include <list>
#include <cstring>

using namespace std;

list<int> adj[1010];
int ks[110], arr[1010];
bool visited[1010];

void dfs(int a) {
    arr[a]++;
    visited[a] = true;
    for (int b : adj[a]) {
	if (!visited[b])
	    dfs(b);
    }
}

int main() {
    int k, n, m, a, b;
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 0; i < k; i++) {
	scanf("%d", &ks[i]);
    }
    for (int i = 0; i < m; i++) {
	scanf("%d %d", &a, &b);
	adj[a].emplace_back(b);
    }

    for (int i = 0; i < k; i++) {
	memset(visited + 1, false, n);
	dfs(ks[i]);
    }

    int rst = 0;
    for (int i = 1; i <= n; i++) {
	if (arr[i] == k)
	    rst++;
    }

    cout << rst << endl;

    return 0;
}
