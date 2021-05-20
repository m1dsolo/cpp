#include <iostream>
#include <list>
#include <queue>
#include <cstring>

using namespace std;
using P = pair<int, int>;

#define INT_MAX 2139062143

int v[510], dis[510];
list<P> adj[510];
bool visited[510];

int n, m, s, d;
int path[510], rst_path[510], size = 0, rst_size, rst_val = 0, rst_num = 0;

int get_min_len() {
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, s});
    while (int size = q.size()) {
	while (size--) {
	    int val = q.top().first, u = q.top().second; q.pop();
	    if (val != dis[u]) continue;
	    for (P p : adj[u]) {
		int v = p.first, len = p.second;
		if (dis[u] + len < dis[v]) {
		    dis[v] = dis[u] + len;
		    q.push({dis[v], v});
		}
	    }
	}
    }
    return dis[d];
}

void dfs(int u, int size, int val, int len, int min_len) {
    if (len > min_len) return;
    path[size++] = u;
    val += v[u];
    if (u == d) {
	if (len == min_len) {
	    rst_num++;
	    if (val > rst_val) {
		rst_val = val;
		memcpy(rst_path, path, sizeof(int) * size);
		rst_size = size;
	    }
	}
	return;
    }
    for (P p : adj[u]) {
	int v = p.first, l = p.second;
	dfs(v, size, val, len + l, min_len);
    }
    val -= v[u];
}

int main() {
    scanf("%d %d %d %d" ,&n, &m, &s, &d);
    for (int i = 0; i < n; i++)
	scanf("%d", &v[i]);
    int u, v, len;
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &u, &v, &len);
	adj[u].push_back({v, len});
	adj[v].push_back({u, len});
    }

    memset(dis, 127, sizeof(dis));
    dis[s] = 0;
    dfs(s, 0, 0, 0, get_min_len());

    printf("%d %d\n", rst_num, rst_val);
    for (int i = 0; i < rst_size - 1; i++) {
	printf("%d ", rst_path[i]);
    }
    printf("%d\n", rst_path[rst_size - 1]);

    return 0;
}
