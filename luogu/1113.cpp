#include <iostream>
#include <list>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
list<int> adj[N];
int arr[N], ind[N], dp[N];

int main() {
    int n, a, b, rst = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf("%d", &b);
	scanf("%d", &arr[b]);
	while (true) {
	    scanf("%d", &a);
	    if (!a) break;
	    adj[a].emplace_back(b);
	    ind[b]++;
	}
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
	if (!ind[i]) {
	    q.emplace(i);
	    dp[i] = arr[i];
	}
    }

    while (int size = q.size()) {
	while (size--) {
	    int a = q.front(); q.pop();
	    for (int b : adj[a]) {
		dp[b] = max(dp[b], dp[a] + arr[b]);
		rst = max(rst, dp[b]);
		if (!--ind[b])
		    q.emplace(b);
	    }
	}
    }

    cout << rst << endl;

    return 0;
}
