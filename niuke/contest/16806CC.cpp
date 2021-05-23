// bitset 01背包
#include <iostream>
#include <bitset>

using namespace std;

const int N = 1e6 + 10;
bitset<N> a, b;

int main() {
    int n, l, r;
    scanf("%d", &n);
    a[0] = 1;
    for (int i = 0; i < n; i++) {
	scanf("%d %d", &l, &r);
	b.reset();
	for (int j = l; j <= r; j++)
	    b |= a << (j * j);
	a = b;
    }

    printf("%d\n", a.count());

    return 0;
}
