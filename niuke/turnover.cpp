#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int rst, val;
    cin >> val;
    rst = val;
    set<int> set;
    set.insert(val);
    for (int i = 1; i < n; i++) {
	scanf("%d", &val);
	auto it = set.lower_bound(val);
	int tmp = abs(*it - val);
	it--;
	tmp = min(tmp, abs(*it - val));
	rst += tmp;
	set.insert(val);
    }

    cout << rst << endl;

    return 0;
}
