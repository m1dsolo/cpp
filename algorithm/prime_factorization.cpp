// 质因数分解 O(sqrt(n))
#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e6;

int f[N], nums[N], cnt;

int main() {
    ll n;
    cin >> n;
    for (int i = 2; i <= n / i; i++) {
	if (!(n % i)) cnt++;
	while (!(n % i)) {
	    f[cnt] = i;
	    nums[cnt]++;
	    n /= i;
	}
	if (a == 1) break;
    }
    if (n > 1) f[++cnt] = n, nums[cnt] = 1;

    for (int i = 1; i <= cnt; i++)
	cout << f[i] << " " << nums[i] << endl;

    return 0;
}
