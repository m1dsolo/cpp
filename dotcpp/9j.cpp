#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<vector<int>> map(k, vector<int>());
    int val;
    for (int i = 0; i < n; i++) {
	scanf("%d", &val);
	map[val % k].push_back(val);
    }
    for (int i = 0; i < k; i++) {
	sort(map[i].begin(), map[i].end(), greater<int>());
    }
    int rst = 0;
    for (int i = 0; i < k; i++) {
	vector<int> &v = map[i];
	if (!v.size())
	    continue;
	else if (v.size() > 1) {
	    if (v.size() > 2) {
		rst = max(rst, v[0] + v[1] + v[2]);
	    }
	    int val = v[0] + v[1];
	    int index = (k - (val % k)) % k;
	    if (map[index].size())
		rst = max(rst, val + map[index][0]);
	}
	for (int j = 0; j < k; j++) {
	    if (j == i) continue;
	    vector<int> &v0 = map[j];
	    if (!v0.size()) continue;
	    int val = v[0] + v0[0];
	    int index = (k - (val % k)) % k;
	    if (map[index].size())
		rst = max(rst, val + map[index][0]);
	}
    }

    cout << rst << endl;

    return 0;
}
