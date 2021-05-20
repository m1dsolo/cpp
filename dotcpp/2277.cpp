#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, vector<int>> map;
    int tmp;
    for (int i = 0; i < n; i++) {
	cin >> tmp;
	map[tmp % k].push_back(tmp);
    }
    int rst = INT_MIN;
    for (auto it = map.begin(); it != map.end(); it++)
	sort(it->second.begin(), it->second.end(), greater<int>());
    for (auto it = map.begin(); it != map.end(); it++) {
	int a = it->second[0];
	for (auto itt = map.begin(); itt != map.end(); itt++) {
	    int b;
	    if (it == itt) {
		if (itt->second.size() < 2) continue;
		b = itt->second[1];
	    }
	    else
		b = itt->second[0];
	    int index = k - (a + b) % k;
	    auto ittt = map.find(index);
	    if (ittt == map.end())
		continue;
	    int c;	
	    if (ittt == it && ittt == itt) {
		if (ittt->second.size() < 3) continue;
		c = ittt->second[2];
	    }
	    else if (ittt == it || ittt == itt) {
		if (ittt->second.size() < 2) continue;
		c = ittt->second[1];
	    }
	    else
		c = ittt->second[0];
	    rst = max(rst, a + b + c);
	}
    }
    cout << rst << endl;

    return 0;
}
