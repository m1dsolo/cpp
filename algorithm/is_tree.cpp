#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> adj;
int n, vertex, edge;
vector<bool> visited;

void add_edge(int a, int b) {
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
}

void dfs(int src) {
    visited[src] = true;
    vertex++;
    for (int dst : adj[src]) {
	edge++;	
	if (!visited[dst])
	   dfs(dst);
    }
}

bool is_tree() {
    dfs(1);

    cout << vertex << " " << edge << endl;

    return vertex - 1 == edge / 2;
}

int main() {
    n = 5;
    adj = vector<list<int>>(n + 1);
    visited = vector<bool>(n + 1);
    add_edge(1, 3);
    add_edge(1, 4);
    add_edge(3, 2);
    add_edge(3, 5);
    add_edge(2, 5);

    //cout << is_tree() << endl;

    return 0;
}
