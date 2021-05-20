#include <iostream>
#include <cmath>

using namespace std;

// 质数一定是6 * x - 1或者6 * x + 1这种形式
bool is_prime(int n) {
    if (n <= 3) return n > 1;
    if (n % 6 != 1 && n % 6 != 5) return false;

    int max_i = sqrt(n);
    for (int i = 5; i <= max_i; i += 6) {
	if ((!(n % i)) || (!(n % (i + 2))))
	    return false;
    }

    return true;
}

int main() {
    for (int i = 1; i <= 100; i++)
	if (is_prime(i)) cout << i << " ";
    cout << endl;

    return 0;
}
