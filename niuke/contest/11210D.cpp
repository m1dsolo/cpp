#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t, m, n, o, num;
    string s;
    cin >> t;
    while (t--) {
	cin >> m >> n;
	unordered_map<string, int> map, submap;
	for (int i = 0; i < m; i++) {
	    cin >> s >> num;
	    map[s] += num;
	}
	for (int i = 0; i < n; i++) {
	    cin >> o;
	    for (int j = 0; j < o; j++) {
		cin >> s;
		submap[s]++;
	    }
	}
	int rst = m;
	for (auto p : map)
	    if (p.second - (n - submap[p.first]) <= 0) rst--;
	if (rst)
	    cout << rst << endl;
	else
	    cout << "Need to be lucky" << endl;
    }

    return 0;
}
