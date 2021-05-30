#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 100;

vector<int> nodes[N];

int main() {
    int n, m, root, node, num;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
	scanf("%d %d", &root, &num);
	for (int j = 0; j < num; j++) {
	    scanf("%d", &node);
	    nodes[root].emplace_back(node);
	}
    }

    vector<int> rst;
    queue<int> q;
    q.emplace(1);
    while (int size = q.size()) {
	int cnt = 0;
	while (size--) {
	    root = q.front(); q.pop();
	    if (!nodes[root].size()) cnt++;
	    else for (int node : nodes[root]) {
		q.emplace(node);
	    }
	}
	rst.emplace_back(cnt);
    }

    for (int i = 0; i < rst.size() - 1; i++)
	cout << rst[i] << " ";
    cout << rst.back() << endl;

    return 0;
}
