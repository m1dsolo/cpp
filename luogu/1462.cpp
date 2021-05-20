#include <iostream>
#include <list>
#include <cstring>
#include <queue>

using namespace std;
using P = pair<int, int>;

int dis[10001], arr[10001];
list<P> adj[10001];

int main() {
    int n, m, hp, a, b, c;
    cin >> n >> m >> hp;
    for (int i = 1; i <= n; i++) {
	scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= m; i++) {
	scanf("%d %d %d", &a, &b, &c);
	adj[a].push_back({b, c});
	adj[b].push_back({a, c});
    }

    memset(dis + 1, 127, sizeof(int) * n);
    
    priority_queue<P, vector<P>, greater<P>> q;
    q.push_back({})


    return 0;
}
