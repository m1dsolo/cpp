#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int t, n, k;
    ll s;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d %lld", &n, &k, &s);
	ll l = ((ll)k + 1) * k / 2, r = ((ll)n * 2 - k + 1) * k / 2;
	printf("%s\n", s >= l && s <= r ? "Yes" : "No");
    }

    return 0;
}
