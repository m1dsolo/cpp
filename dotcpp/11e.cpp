#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int rst = 0;
vector<vector<bool>> graph(7, vector<bool>(7, false));
vector<int> parents(7);
vector<bool> lights(7, false);

int find(int a) {
    return a == parents[a] ? a : parents[a] = find(parents[a]);
}

void merge(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 != p2) {
	parents[p2] = p1;
    }
}

void dfs(int index) {
    if (index == 7) {
	iota(parents.begin(), parents.end(), 0);
	for (int i = 1; i < 7; i++) {
	    if (!lights[i]) continue;
	    for (int j = 0; j < i; j++) {
		if (lights[j] && graph[i][j])
		    merge(i, j);
	    }
	}
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
	    if (lights[i] && i == find(i)) cnt++;
	}
	if (cnt == 1) rst++;
    }
    else {
	dfs(index + 1);
	lights[index] = true;
	dfs(index + 1);
	lights[index] = false;
    }
}

int main() {
    graph[0][1] = true;
    graph[0][5] = true;
    graph[1][0] = true;
    graph[1][2] = true;
    graph[1][6] = true;
    graph[2][1] = true;
    graph[2][3] = true;
    graph[2][6] = true;
    graph[3][2] = true;
    graph[3][4] = true;
    graph[4][3] = true;
    graph[4][5] = true;
    graph[4][6] = true;
    graph[5][0] = true;
    graph[5][4] = true;
    graph[5][6] = true;
    graph[6][1] = true;
    graph[6][2] = true;
    graph[6][4] = true;
    graph[6][5] = true;

    dfs(0);

    cout << rst << endl;

    return 0;
}
