// https://zhuanlan.zhihu.com/p/240077462

// 切线y = f'(x0) * (x - x0) + f(x0), 所以与x轴交点的x1 = x0 - f(x0) / f'(x0)
#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 3) - 1.8 * pow(x, 2) - 8.59 * x - 0.84;
}

double df(double x) {
    return 3 * pow(x, 2) - 3.6 * x - 8.59;
}

int main() {
    double x = -5;
    for (int i = 0; i < 10; i++) {
	x = x - f(x) / df(x);
	cout << x << endl;
    }

    return 0;
}
