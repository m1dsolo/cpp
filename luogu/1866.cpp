#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
	cin >> v[i];
    sort(v.begin(), v.end());

    int cnt = 0;
    long long rst = 1;
    for (int num : v) {
	if (num <= cnt) {
	    cout << 0 << endl;
	    return 0;
	}
	rst = (rst * (num - cnt)) % mod;
	cnt++;
    }

    cout << rst << endl;

    return 0;
}
