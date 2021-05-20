#include <iostream>
#include <vector>
#include <numeric>	// iota

using namespace std;

class UnionFind {
private:
    vector<int> parents;
    vector<int> ranks;
public:
    UnionFind(int n) : parents(n), ranks(n, 0) {
	iota(parents.begin(), parents.end(), 0);
    };

    // node0 is parent
    void merge(int node0, int node1) {
	int root0 = find(node0);
	int root1 = find(node1);
	if (root0 != root1) {
	    if (ranks[root0] < ranks[root1])
		swap(root0, root1);
	    parents[root1] = root0;
	    if (ranks[root0] == ranks[root1]) ranks[root0] += 1;
	}
    };

    int find(int node) {
	return (node == parents[node]) ? node : (parents[node] = find(parents[node]));
    };

    bool is_connected(int node0, int node1) {
	return find(node0) == find(node1);
    };

    void print() {
	for (int i = 0; i < parents.size(); i++) {
	    cout << i << "(" << find(i) << ") ";
	    if (!((i + 1) % 4))
		cout << endl;
	}
    };
};

int main() {
    UnionFind uf(10);
    uf.merge(1, 2);
    uf.merge(7, 8);
    uf.merge(1, 8);
    uf.print();
}
