#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> path;
vector<vector<int>> rst;
void dfs(int sum) {
    if (!sum) {
	rst.push_back(path);
	return;
    }
    for (int i = 1; i <= sum; i++) {
	path.push_back(i);
	dfs(sum - i);
	path.pop_back();
    }
}

// 能否按字典序？
// 有问题
void bfs(int sum) {
    queue<pair<int, vector<int>>> q;
    for (int i = 1; i < sum; i++) {
	q.push({i, vector<int>{i}});
    }
    while (q.size()) {
	int n = q.size();
	while (n--) {
	    int num = q.front().first;
	    vector<int> v = q.front().second;
	    q.pop();
	    if (num == sum)
		rst.push_back(v);
	    for (int i = 1; i <= (sum - num); i++) {
		v.push_back(i);
		q.push({num + i, v});
	    }
	}
    }
}

void split_num(int sum) {
    //dfs(sum);
    bfs(sum);
};

int main() {
    split_num(5);
    for (vector<int> &v : rst) {
	for (int num : v) {
	    cout << num << " ";
	}
	cout << endl;
    }

    return 0;
}
