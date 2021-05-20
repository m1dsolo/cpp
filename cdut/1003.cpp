#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    long long a, b, g;
    while (cin >> a >> b) {
	g = gcd(a, b);
	a /= g, b /= g;
	if (b == 1)
	    cout << a << endl;
	else
	    cout << a << '/' << b << endl;
    }

    return 0;
}
