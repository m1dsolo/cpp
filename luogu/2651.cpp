#include <iostream>

using namespace std;

const int N = 1e4 + 10;

int arr[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int t, n, a, rst;
    scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	scanf("%d %d", &a, &rst);
	rst /= gcd(rst, a);
	for (int i = 3; i <= n; i++) {
	    scanf("%d", &a);
	    rst /= gcd(rst, a);
	}
	printf("%s\n", rst == 1 ? "Yes" : "No");
    }

    return 0;
}
