#include <iostream>
#include <list>
#include <queue>

using namespace std;

const int N = 5010, mod = 80112002;

list<int> adj[N]; 
int ind[N], outd[N], nums[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int u, v;
    while (m--) {
	scanf("%d %d", &u, &v);
	adj[v].emplace_back(u);
	ind[u]++;
	outd[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
	if (!ind[i]) {
	    q.emplace(i);
	    nums[i]++;
	}
    }

    int rst = 0;
    while (int size = q.size()) {
	while (size--) {
	    int u = q.front(); q.pop();
	    for (int v : adj[u]) {
		nums[v] = (nums[v] + nums[u]) % mod;
		if (!--ind[v]) {
		    if (!outd[v]) {
			rst = (rst + nums[v]) % mod;
			continue;
		    }
		    q.emplace(v);
		}
	    }
	}
    }

    printf("%d\n", rst);

    return 0;
}
