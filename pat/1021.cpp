// 这题思路牛逼
#include <iostream>
#include <list>
#include <queue>
#include <numeric>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;
int parents[N];
list<int> adj[N];
bool visited[N];
vector<int> rst;

int find(int a) {
    return a == parents[a] ? a : parents[a] = find(parents[a]);
}

void merge(int a, int b) {
    int p1 = find(a), p2 = find(b);
    if (p1 != p2)
	parents[p2] = p1;
}

void bfs(queue<int> &q) {
    vector<int> vec;
    while (int size = q.size()) {
	vec.clear();		// 有没有更优雅的几乎最后一层的方法？
	while (size--) {
	    int u = q.front(); q.pop();
	    vec.emplace_back(u);
	    for (int v : adj[u]) {
		if (!visited[v]) {
		    q.emplace(v);
		    visited[v] = true;
		}
	    }
	}
    }
    for (int a : vec)
	rst.emplace_back(a);
}

int main() {
    int n;
    scanf("%d", &n);
    iota(parents + 1, parents + 1 + n, 1);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
	scanf("%d %d", &u, &v);	
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
	merge(u, v);
    }

    int num = 0;
    for (int i = 1; i <= n; i++) {
	if (parents[i] == i)
	    num++;
    }
    if (num > 1)
	printf("Error: %d components\n", num);
    else {
	queue<int> q;	
	q.emplace(1);
	visited[1] = true;
	bfs(q);
	memset(visited + 1, false, n);
	q.emplace(rst.front());
	bfs(q);

	sort(rst.begin(), rst.end());
	int n = unique(rst.begin(), rst.end()) - rst.begin();
	for (int i = 0; i < n; i++)
	    printf("%d\n", rst[i]);
    }

    return 0;
}
