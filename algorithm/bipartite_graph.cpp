#include <iostream>
#include <list>

using namespace std;

const int N = 100;

list<int> adj[N];

int find(int a) {
    return a == ps[a] ? a : ps[a] = find(ps[a]);
}

void merge(int a, int b) {
    int p1 = find(a), p2 = find(b);
    if (p1 != p2)
	ps[p2] = p1;
}

// union find
bool is_bipartite_graph() {
    

}
int main() {

    return 0;
}
