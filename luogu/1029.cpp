#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int x, y;
    cin >> x >> y;
    long long n = x * y;
    int max_i = sqrt(n);
    int rst = 0;
    for (int i = 1; i < max_i; i++) {
	if (!(n % i) && gcd(i, n / i) == x)
	    rst += 2;
    }

    if ((long long)max_i * max_i == n && max_i == x)
	rst++;

    cout << rst << endl;

    return 0;
}
