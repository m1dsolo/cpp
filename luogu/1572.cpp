#include <iostream>

using namespace std;

inline int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

inline int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int a, b, c, d, g, l;
    scanf("%d/%d", &a, &b);
    while (scanf("%d/%d", &c, &d) != EOF) {
	l = lcm(b, d);
	a = a * l / b + c * l / d;
	b = l;
	g = gcd(a, b);
	a /= g;
	b /= g;
    }

    if (b < 0) {
	a = -a;
	b = -b;
    }

    if (b == 1) cout << a << endl;
    else cout << a << '/' << b << endl;

    return 0;
}
