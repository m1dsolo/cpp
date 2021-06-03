#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 1e6;

int main() {
    ll n, rst = 1;
    cin >> n;
    for (int i = 2; i <= n / i; i++) {
	int num = 0;
	while (!(n % i)) {
	    n /= i;
	    num++;
	}
	if (num & 1) rst *= i;
    }
    printf("%lld\n", rst * n);

    return 0;
}
