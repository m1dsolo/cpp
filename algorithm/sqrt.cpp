// 本质牛顿迭代法求解f(x) = x ** 2 - a的解
// x1 = x0 - f(x0) / f'(x0), f(x)代入化简得 x1 = (x0 + a / x0) / 2

#include <iostream>

using namespace std;

double sqrt(double a) {
    double x = 10;   // 从10开猜
    for (int i = 0; i < 20; i++)
	x = (x + a / x) / 2;
    return x;
}

int main() {
    for (int i = 0; i < 10; i++) {
	cout << i << ':' << sqrt(i) << endl;
    }

    return 0;
}
