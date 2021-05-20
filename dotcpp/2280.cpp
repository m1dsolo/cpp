#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = 1e9 + 9;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
	cin >> v[i];
    sort(v.begin(), v.end());

    int left = 0, right = n - 1;
    int sign = 1;
    long long rst = 1;

    if (k % 2) {
	rst = v[right--];
	k--;
	// 全为负，k还是奇数就要可小了取
	if (rst < 0)
	    sign = -1;
    }

    while (k) {
	long long a = v[left] * v[left + 1], b = v[right] * v[right - 1];
	if (a * sign > b * sign) {
	    rst = a % mod * rst % mod;
	    left += 2;
	}
	else {
	    rst = b % mod * rst % mod;
	    right -= 2;
	}
	k -= 2;
    }
    cout << rst << endl;

    return 0;
}
