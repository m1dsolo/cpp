// https://zhuanlan.zhihu.com/p/139112162

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
    bool is_ok = false;
    vector<vector<int>> paths;

public:
    Graph (int n) {
	paths = vector<vector<int>>(n, vector<int>(n, INT_MAX));
	for (int i = 0; i < n; i++)
	    paths[i][i] = 0;
    };

    // to seek the shortest path in graph
    void floyd() {
	int n = paths.size();
	for (int k = 0; k < n; k++) {
	    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		    if (paths[i][k] != INT_MAX && paths[k][j] != INT_MAX)
			paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);
		}
	    }
	}
	is_ok = true;
    };

    void insert(int a, int b, int len) {
	paths[a][b] = len;
	paths[b][a] = len;
	is_ok = false;
    };

    void get_min_path(int a, int b) {
	if (!is_ok) floyd();	
	cout << paths[a][b];
    };

    void print() {
	if (!is_ok) floyd();
	for (int i = 0; i < paths.size(); i++) {
	    for (int j = 0; j < paths.size(); j++) {
		cout << ((paths[i][j] == INT_MAX) ? "oo" : to_string(paths[i][j])) << " ";
	    }
	    cout << endl;
	}
    };
};

int main() {
    Graph g(6);
    g.insert(0, 1, 7);
    g.insert(0, 4, 1);
    g.insert(0, 5, 6);
    g.insert(1, 2, 2);
    g.insert(1, 3, 4);
    g.insert(2, 3, 9);
    g.insert(2, 4, 3);
    g.insert(4, 5, 3);

    g.print();

    return 0;
}
