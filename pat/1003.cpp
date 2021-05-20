#include <iostream>
#include <queue>
#include <list>
#include <cstring>

using namespace std;
using P = pair<int, int>;

const int N = 510, INT_MAX = 2139062143;

int n, m, s, d, u, v, w, val;
int arr[N], dis[N];
list<P> adj[N];

int min_path_num, max_people, min_len;
bool visited[N];
void dfs(int u, int len, int num) {
    if (len > min_len) return;
    num += arr[u];
    visited[u] = true;
    if (u == d) {
	max_people = max(max_people, num);
	min_path_num++;
    }
    else {
	for (auto p : adj[u]) {
	    v = p.first, w = p.second;
	    if (!visited[v])
		dfs(v, len + w, num);	
	}
    }
    visited[u] = false;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &u, &v, &w);
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
    }

    memset(dis, 127, sizeof(int) * n);
    dis[s] = 0;

    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, s});
    while (int size = q.size()) {
	while (size--) {
	    val = q.top().first, u = q.top().second; q.pop();
	    if (val != dis[u]) continue;
	    for (P p : adj[u]) {
		v = p.first, w = p.second;
		if (dis[u] + w < dis[v]) {
		    dis[v] = dis[u] + w;
		    q.push({dis[v], v});
		}
	    }
	}
    }

    min_len = dis[d];
    dfs(s, 0, 0);

    cout << min_path_num << " " << max_people << endl;

    return 0;
}
