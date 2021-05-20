#include <iostream>
#include <list>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
using P = pair<int, int>;

const int N = 1e6, INT_MAX = 2139062143, mod = 1e5 + 3;

int c, n, d, m;
int arr[N], dis[N], num[N] = {0, 1};
list<int> adj[N];
bool visited[N];

int main() {
    scanf("%d %d", &n, &m);
    int u, v;
    while (m--) {
	scanf("%d %d", &u, &v);	
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
    }

    memset(dis + 2, 127, sizeof(int) * (n - 1));
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, 1});
    while (int size = q.size()) {
	while (size--) {
	    int val = q.top().first, u = q.top().second; q.pop();
	    if (dis[u] != val) continue;
	    for (int v : adj[u]) {
		if (dis[u] + 1 < dis[v]) {
		    dis[v] = dis[u] + 1;
		    q.push({dis[v], v});
		    num[v] = num[u];
		}
		else if (dis[u] + 1 == dis[v])
		    num[v] = (num[v] + num[u]) % mod;
	    }
	}
    }

    for (int i = 1; i <= n; i++)
	printf("%d\n", num[i]);

    return 0;
}
