#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> v(n + 1, true);
    v[0] = v[1] = false;
    for (int i = 2; i < v.size(); i++) {
	if (v[i]) {
	    cout << i << endl;
	    for (int j = i * i; j < v.size(); j += i) {
		v[j] = false;
	    }
	}
    }

    return 0;
}
