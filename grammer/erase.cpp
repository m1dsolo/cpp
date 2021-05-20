#include <iostream>
#include <map>
#include <vector>

using namespace std;

void map_erase() {
    map<int, int> map{{1, 10}, {2, 20}, {3, 30}, {2, 40}};
    for (auto it = map.begin(); it != map.end();) {
	if (it->first == 2)
	    map.erase(it++);	    // 会删掉tmp = it这个临时变量，同时it已经变为了it + 1(不能想vector一样删除，因为erase不返回it下一个位置)
	else
	    it++;
    }

    for (auto p : map)
	cout << p.first << " " << p.second << endl;
}

void vector_erase() {
    vector<int> v{1, 2, 3, 2};
    for (auto it = v.begin(); it != v.end();) {
	if (*it == 2)
	    it = v.erase(it);	    // 如果写v.erase(it++)会报错，不太清楚为什么
	else
	    it++;
    }

    for (int a : v)
	cout << a << endl;
}

int main() {
    map_erase();

    return 0;
}
