#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int sum[N];

int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf("%d", &a);
	sum[i] = sum[i - 1] + a;
    }

    int m;
    scanf("%d", &m);
    while (m--) {
	scanf("%d %d", &a, &b);
	if (a > b) swap(a, b);
	printf("%d\n", min(sum[b - 1] - sum[a - 1], sum[n] - sum[b - 1] + sum[a - 1]));
    }

    return 0;
}
