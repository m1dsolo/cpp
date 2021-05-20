#include <iostream>
#include <numeric>

using namespace std;

const int N = 1e4 + 10;

int parents[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int find(int a) {
    return a == parents[a] ? a : parents[a] = find(parents[a]);
}

void merge(int a, int b) {
    int p1 = find(a), p2 = find(b);
    if (!p1 != p2)
	parents[p2] = p1;
}

int main() {
    int t;
    scanf("%d", &t);
    iota(parents + 1, parents + N, 1);
    int a, x, b, y;
    while (t--) {
	scanf("%d %d %d %d", &a, &x, &b, &y);
	if (gcd(x, y) == 1)
	    merge(a, b);
    }

    scanf("%d", &t);
    while (t--) {
	scanf("%d %d", &a, &b);
	printf("%c\n", find(a) == find(b) ? 'Y' : 'N');
    }

    return 0;
}
