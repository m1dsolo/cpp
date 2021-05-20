// luogu 4017(求拓扑路径条数)
// luogu 1137(求每个节点为终点最大路径节点个数)
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

// 判断是否是有向无环图(DAG),如果是则返回任意一条拓扑序,同时求拓扑序个数(路径个数)
// 还可以求DAG最长路径，见洛谷1113(点), 1807(边)
// O(n + m)
vector<int> topological_sort(int n, vector<vector<int>> &vv) {
    vector<int> ind(n + 1), outd(n + 1), vals(n + 1), rst;
    vector<list<int>> adj(n + 1);
    int sum = 0;
    for (const vector<int> &v : vv) {
	ind[v[1]]++;
	outd[v[0]]++;
	adj[v[0]].emplace_back(v[1]);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
	if (!ind[i]) {
	    vals[i] = 1;
	    q.emplace(i);
	}
    }
    while (int size = q.size()) {
	while (size--) {
	    int a = q.front(); q.pop(); n--;
	    rst.emplace_back(a);
	    for (int b : adj[a]) {
		vals[b] += vals[a];
		if (!--ind[b]) {
		    if (!outd[b]) {
			sum += vals[b];
			//continue;	// 这句可有可无,如果还要求任意一条拓扑序，那么必须删掉
		    }
		    q.emplace(b);
		}
	    }
	}
    }
    cout << sum << endl;
    return n ? vector<int>() : rst;
}

int main() {
    vector<vector<int>> vv{{1, 2}, {1, 3}, {2, 3}, {3, 5}, {2, 5}, {4, 5}, {3, 4}};

    vector<int> rst = topological_sort(5, vv);
    for (int a : rst) {
	cout << a << " ";
    }
    cout << endl;

    return 0;
}
