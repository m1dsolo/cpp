#include <iostream>
#include <map>

using namespace std;

int main() {
    int k = 2, n, key;
    double val;
    map<int, double> map;
    while (k--) {
	cin >> n;
	while (n--) {
	    cin >> key >> val;
	    map[key] += val;
	}
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
