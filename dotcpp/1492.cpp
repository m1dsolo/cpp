#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s; 
    int k;
    cin >> s >> k;
    vector<int> v(10, 1);
    for (int i = 0; i < k; i++) {
	int x, y;
	cin >> x >> y;
	v[x]++;
    }

    int rst = 1;
    for (char c : s) {
	rst *= v[c - '0'];
    }

    cout << rst << endl;

    return 0;
}
