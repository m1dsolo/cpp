#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int tolls[24];

map<string, vector<pair<string, bool>>> map;

int main() {
    sync_with_stdio(false);
    for (int i = 0; i < 24; i++)
	cin >> tolls[i];
    int n;
    cin >> n;
    string name, time, flag;
    for (int i = 0; i < n; i++) {
	cin >> name >> time >> flag;
	map[name].push_back({time, flag[1] == 'n'});
    }

    int month1, day1, hour1, minute1;
    for (auto p : map) {
	string &name = p.first;
	auto &v = p.second;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) {
	    if (v[i].second && !v[i + 1].second) {
		sscanf(v[i]."%d:%d:%d:%d", )
	    }
	}
    }



    return 0;
}
