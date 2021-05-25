// https://blog.csdn.net/Flag_z/article/details/99163939
#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e6 + 10;

int c[N << 2], rst[N << 2];
string s1, s2;
int l = 1;

struct cp {
    double r = 0, i = 0;
    cp() {}
    cp(double r, double i) : r(r), i(i) {}
    inline cp operator+(const cp &c) const { return {r + c.r, i + c.i}; }
    inline cp operator-(const cp &c) const { return {r - c.r, i - c.i}; }
    inline cp operator*(const cp &c) const { return {r * c.r - i * c.i, r * c.i + i * c.r}; }
    inline void operator*=(const cp &c) { *this = *this * c; }

} a[N << 2], b[N << 2];

void fft(cp *a, int op) {
    for (int i = 0; i < l; i++) {
	if (i < c[i])
	    swap(a[i], a[c[i]]);
    }
    for (int i = 1; i < l; i <<= 1) {
	cp wn(cos(M_PI / i), op * sin(M_PI / i));
	//cp wn = exp(cp(0, op * M_PI / l).r, cp(0, op * M_PI / l).i);
	for (int j = 0; j < l; j += (i << 1)) {
	    cp w(1, 0);
	    for (int k = 0; k < i; k++, w *= wn) {
		cp x = a[j + k], y = w * a[j + k + i];
		a[j + k] = x + y, a[j + k + i] = x - y;
	    }
	}
    }
    if (op == -1) {
	for (int i = 0; i < l; i++)
	    a[i].r /= l;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    for (int i = 0; i < n; i++)
	a[n - 1 - i].r = s1[i] - '0';
    for (int i = 0; i < m; i++)
	b[m - 1 - i].r = s2[i] - '0';

    int digit = 0;
    while (l <= n + m) {
	l <<= 1;
	digit++;
    }

    cout << l << " " << digit << endl;

    for (int i = 0; i < l; i++)
	c[i] = (c[i >> 1] >> 1) | ((i & 1) << (digit - 1));

    fft(a, 1), fft(b, 1);
    for (int i = 0; i < l; i++)
	a[i] *= b[i];
    fft(a, -1);

    for (int i = 0; i < n + m; i++)
	rst[i] = a[i].r + 0.5;
    for (int i = 0; i < n + m - 1; i++) {
	rst[i + 1] += rst[i] / 10;
	rst[i] %= 10;
    }

    l = n + m;
    while (l >= 0 && !rst[l])
	l--;

    while (l >= 0)
	cout << rst[l--];
    cout << endl;

    return 0;
}
