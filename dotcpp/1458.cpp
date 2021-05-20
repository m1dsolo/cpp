#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int val;
    while (n--) {
	while (cin >> val) {
	    v.push_back(val);
	    if (cin.get() == '\n')
		break;
	}
    }
    sort(v.begin(), v.end());

    int a, b;
    for (int i = 1; i < v.size(); i++) {
	if (v[i] == v[i - 1])
	    b = v[i];
	else if (v[i] == v[i - 1] + 2)
	    a = v[i] - 1;
    }

    cout << a << " " << b << endl;

    return 0;
}
