#include <iostream>
#include <list>

using namespace std;

const int N = 2e5 + 10, mod = 1e4 + 7;

int n, arr[N];
list<int> adj[N];

int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
	scanf("%d %d", &u, &v);
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);

    int rst1 = 0, rst2 = 0;
    for (int u = 1; u <= n; u++) {
	int max_val = 0, submax_val = 0, a = 0, b = 0;
	for (int v : adj[u]) {
	    if (arr[v] > max_val) {
		submax_val = max_val;
		max_val = arr[v];
	    }
	    else if (arr[v] > submax_val)
		submax_val = arr[v];
	    a = (a + arr[v]) % mod;
	    b = (b + arr[v] * arr[v]) % mod;
	}
	rst1 = max(rst1, max_val * submax_val);
	rst2 = (rst2 + a * a - b) % mod;
    }

    printf("%d %d\n", rst1, rst2);

    return 0;
}
