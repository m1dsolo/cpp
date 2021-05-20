#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m, val;
    map<int, int> map;
    while (cin >> n >> m) {
	for (int i = 0; i < n; i++) {
	    scanf("%d", &val);
	    map[val]++;
	}
	int rst = 0;
	while (map.size() >= 2) {
	    auto it1 = map.begin();
	    auto it2 = --map.lower_bound(it1->first + m);
	    if (it1 == it2) {
		if (it1->second >= 2) {
		    rst++;
		    if (!(it1->second -= 2))
			map.erase(it1);
		}
		else
		    map.erase(it1);
	    }
	    else if (it2->first > it1->first) {
		rst++;
		if (!(--it1->second))
		    map.erase(it1);
		if (!(--it2->second))
		    map.erase(it2);
	    }
	    else
		break;
	}
	cout << rst << endl;
    }

    return 0;
}
