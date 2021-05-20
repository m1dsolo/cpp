#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second - a.first < b.second - b.first;
}

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
	int n;
	cin >> n;
	int sum = 0;
	int max_need = INT_MIN;
	vector<pair<int, int>> v;
	for (int j = 0; j < n; j++) {
	    int have, need;
	    cin >> have >> need;
	    if (have - need >= 0)
		sum += have;
	    else
		v.push_back(make_pair(have, need));
	}

	sort(v.begin(), v.end(), cmp);
	bool ok = true;
	for (int i = 0; i < v.size(); i++) {
	    if (sum < v[i].second - v[i].first) {
		cout << "NO" << endl;
		ok = false;
		break;
	    }
	    else {
		sum += v[i].first;
	    }
	}
	if (ok) {
	    cout << "YES" << endl;
	}
    }

    return 0;
}
