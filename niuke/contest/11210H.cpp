#include <iostream>
#include <list>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;
using P = pair<ll, int>;

const int N = 110;
ll dis[N];

int main() {
    int t, n, m, s, d, f, u, v, a, b, c;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d %d %d %d", &n, &m, &s, &d, &f);
	list<P> adj[N];	    // 不好清理
	for (int i = 0; i < m; i++) {
	    scanf("%d %d %d %d %d", &u, &v, &a, &b, &c);
	    ll val = (ll)min(f, b) * a + (ll)max(f - b, 0) * c;
	    adj[u].push_back({val, v});
	}
	memset(dis + 1, 0x3f, sizeof(ll) * n);
	dis[s] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({0, s});
	while (int size = q.size()) {
	    while (size--) {
		ll val = q.top().first; 
		int u = q.top().second; q.pop();
		if (dis[u] != val) continue;
		for (P p : adj[u]) {
		    ll len = p.first;
		    int v = p.second;
		    if (dis[u] + len < dis[v])
			q.push({dis[v] = dis[u] + len, v});
		}
	    }
	}
	printf("%lld\n", dis[d]);
    }

    return 0;
}
