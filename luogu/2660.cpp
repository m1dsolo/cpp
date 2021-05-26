#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ll rst = 0;
    if (a < b) swap(a, b);
    while (b) {
	rst += b * 4 * (a / b);
	ll tmp = a;
	a = b;
	b = tmp % b;
    }

    printf("%lld\n", rst);

    return 0;
}
