#include <iostream>

using namespace std;
using ll = long long;

const int N = 3e6 + 10;
int invs[N];

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    printf("%d\n", invs[1] = 1);
    for (int i = 2; i <= n; i++)
	printf("%d\n", invs[i] = (ll)(p - p / i) * invs[p % i] % p);

    return 0;
}
