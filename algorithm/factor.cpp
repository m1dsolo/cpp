// 因数分解 O(sqrt(n))
#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e6;

int f[N], cnt;

int main() {
    ll n;
    cin >> n;
    int i;
    for (i = 1; i < n / i; i++) {
	if (!(n % i)) {
	    f[cnt++] = i;
	    f[cnt++] = n / i;
	}
    }
    if (i * i == n)
	f[cnt++] = i;

    for (int i = 0; i < cnt; i++)
	cout << f[i] << " ";
    cout << endl;

    return 0;
}
