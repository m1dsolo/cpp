#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
//#include <fstream>
#include <unordered_map>

using namespace std;

struct Store {
    int priority = 0;
    bool ok = false;
};

int main() {
    //ifstream ifs("data");
    int n, m, t;
    cin >> n >> m >> t;
    //ifs >> n >> m >> t;
    vector<pair<int, int>> orders(m, pair<int, int>());
    for (int i = 0; i < m; i++) 
	cin >> orders[i].first >> orders[i].second;
	//ifs >> orders[i].first >> orders[i].second;
    sort(orders.begin(), orders.end());

    Store stores[n];

    int ptr = 0;
    for (int i = 1; i <= t; i++) {
	unordered_map<int, int> map;
	while (ptr < m && orders[ptr].first == i) {
	    map[orders[ptr++].second - 1]++;
	}
	for (int j = 0; j < n; j++) {
	    Store &s = stores[j];
	    if (map[j]) {
		s.priority += (2 * map[j]);
		if (s.priority > 5)
		    s.ok = true;
	    }
	    else {
		s.priority = max(s.priority - 1, 0);
		if (s.priority <= 3)
		    s.ok = false;
	    }
	}
    }

    int rst = 0;
    for (int i = 0; i < n; i++)
	rst += stores[i].ok;
    cout << rst << endl;

    return 0;
}
