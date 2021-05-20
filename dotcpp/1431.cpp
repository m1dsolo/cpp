#include <iostream>
#include <vector>

using namespace std;


bool finish(vector<int> &v) {
    if (!v.size()) return true;
    for (int i = 1; i < v.size(); i++) {
	if (v[i] != v[0])
	    return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
	int val;
	cin >> val;
	v.push_back(val);
    }

    int rst = 0;
    while (!finish(v)) {
	vector<int> tmp(v.size());
	for (int i = 0; i < v.size(); i++) {
	    tmp[i] = v[(i + 1) % v.size()] / 2 - v[i] / 2;
	}
	for (int i = 0; i < v.size(); i++) {
	    v[i] += tmp[i];
	}

	for (int i = 0; i < v.size(); i++) {
	    if (v[i] % 2) {
		v[i]++;
		rst++;
	    }
	}
    }

    cout << rst << endl;
    return 0;
}
