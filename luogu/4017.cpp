#include <iostream>
#include <list>
#include <queue>

using namespace std;

int ind[5001], outd[5001], v[5001];
list<int> adj[5001];

const int mod = 80112002;

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
	scanf("%d %d", &a, &b);
	ind[b]++;
	outd[a]++;
	adj[a].emplace_back(b);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
	if (!ind[i]) {
	    v[i] = 1;
	    q.emplace(i);
	}
    }
    int rst = 0;
    while (int size = q.size()) {
	while (size--) {
	    int a = q.front(); q.pop();
	    for (int b : adj[a]) {
		v[b] = (v[b] + v[a]) % mod;
		if (!--ind[b]) {
		    if (!outd[b]) {
			rst = (rst + v[b]) % mod;
			continue;
		    }
		    q.emplace(b);
		}
	    }
	}
    }
    cout << rst << endl;

    return 0;
}
