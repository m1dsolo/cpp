#include <iostream>

using namespace std;

const int N = 1e6 + 10;

struct cpx {
    double r = 0, i = 0;
    cpx() {}
    cpx(double r, double i) : r(r), i(i) {}
    inline cpx operator+(const cpx &c) const { return {r + c.r, i + c.i}; }
    inline cpx operator-(const cpx &c) const { return {r - c.r, i - c.i}; }
    inline cpx operator*(const cpx &c) const { return {r * c.r - i * c.i, r * c.i + i * c.r}; }
    inline void operator*=(const cpx &c) { *this = *this * c; }
} a[N << 2], b[N << 2];

int s1[N], s2[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
	scanf("%d", &s1[i]);
    for (int i = 0; i <= m; i++)
	scanf("%d", &s2[i]);



    return 0;
}
