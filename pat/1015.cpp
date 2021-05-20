#include <iostream>
#include <cmath>

using namespace std;

int get_reverse(int n, int d) {
    int rst = 0;
    while (n) {
	rst = rst * d + n % d;
	n /= d;
    }
    return rst;
}

bool is_prime(int n) {
    if (n <= 3) return n > 1;
    if (n % 6 != 1 && n % 6 != 5) return false;
    int max_i = sqrt(n);
    for (int i = 5; i <= max_i; i += 6) {
	if (!(n % i) || !(n % (i + 2))) return false;
    }

    return true;
}

int main() {
    int n, d;
    while (scanf("%d %d", &n, &d) != EOF) {
	if (n < 0) break;
	printf("%s\n", is_prime(n) && is_prime(get_reverse(n, d)) ? "Yes" : "No");
    }

    return 0;
}
