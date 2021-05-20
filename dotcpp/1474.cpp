#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v = {1};
    int carry = 0;
    for (int i = 1; i <= n; i++) {
	for (int j = 0; j < v.size(); j++) {
	    int val = v[j] * i + carry;
	    v[j] = val % 10;
	    carry = val / 10;
	}
	while (carry) {
	    v.push_back(carry % 10);
	    carry /= 10;
	}
    }
    for (int i = v.size() - 1; i >= 0; i--) {
	cout << v[i];
    }
    cout << endl;

    return 0;
}
