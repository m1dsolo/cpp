#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, d, k;
    scanf("%d %d %d", &n, &d, &k);
    unordered_map<int, vector<int>> map;
    int ts, id;
    for (int i = 0; i < n; i++) {
	scanf("%d %d", &ts, &id);
	map[id].push_back(ts);
    }
    vector<int> rst;
    for (auto it = map.begin(); it != map.end(); it++) {
	vector<int> &v = it->second;
	sort(v.begin(), v.end());
	int max_i = v.size() - k + 1;
	for (int i = 0; i < max_i; i++) {
	    if (v[i + k - 1] - v[i] < d) {
		rst.push_back(it->first);
		break;
	    }
	}
    }
    sort(rst.begin(), rst.end());
    for (int a : rst)
	printf("%d\n", a);

    return 0;
}
