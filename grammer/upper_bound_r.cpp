#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v{100, 100, 50, 40, 40, 20, 10}, query{5, 25, 50, 120};

    // 找出大于v[i]元素的下标
    for (int q : query) {
	auto it = upper_bound(v.rbegin(), v.rend(), q);
	cout << v.rend() - it - 1 << endl;
    }

    // 找出小于等于val的元素
    cout << *lower_bound(v.begin(), v.end(), 120, greater<int>()) << endl;

    return 0;
}
