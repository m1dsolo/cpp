#include <iostream>
#include <list>

using namespace std;

const int N = 3e3 + 10;

list<int> adj[N];
int money[N];

int main() {
    int n, m, k, a, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n - m; i++) {
	scanf("%d", &k);
	while (k--) {
	    scanf("%d %d", &a, &c);
	    adj[a].emplace_back(c);
	}
    }

    return 0;
}
