#include <iostream>
#include <map>

using namespace std;

pair<int, double> arr[11];

int main() {
    int k1, k2, key, tmp;
    double val;
    map<int, double> map;
    cin >> k1;
    for (int i = 0; i < k1; i++)
	cin >> arr[i].first >> arr[i].second;
    cin >> k2;
    for (int i = 0; i < k2; i++) {
	cin >> key >> val;
	for (int j = 0; j < k1; j++)
	    map[key + arr[j].first] += arr[j].second * val;
    }

    for (auto it = map.begin(); it != map.end();) {
	if (!it->second)
	    map.erase(it++);
	else
	    it++;
    }

    cout << map.size();
    for (auto it = map.rbegin(); it != map.rend(); it++)
	printf(" %d %.1lf", it->first, it->second);
    cout << endl;

    return 0;
}
