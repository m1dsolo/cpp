#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int rst = 1;
    for (int i = 0; i < n; i++) {
	int val;
	cin >> val;
	v.push_back(val);
	// virus behind normal and different direction(clever)
	if (v[i] + v[0] < 0 && (v[i] ^ v[0]) < 0) rst++;
    }
    
    if (rst != 1) {
	for (int i = 1; i < n; i++) {
	    // normal behind virus and same direction(clever)
	    if (v[i] < v[0] && (v[i] * v[0]) > 0) rst++;
	}
    }

    cout << rst << endl;

    return 0;
}
