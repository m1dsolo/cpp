#include <iostream>

using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
	x = 1; 
	y = 0;
	return a;
    }
    else {
	int rst = exgcd(b, a % b, y, x);
	y -= x * (a / b);
	return rst;
    }
}

int niyuan(int a, int b) {
    int x, y;
    exgcd(a, b, x, y);

    return (x + b) % b;
}

int qpow(int a, int n, int p) {
    int rst = 1;
    while (n) {
	if (n & 1) rst = (rst * a) % p;
	n >>= 1;
	a = (a * 2) % p;
    }
    return rst;
}

 //exgcd求逆元
 //a要小于p
//int inv(int a, int p) {
    //return a == 1 ? 1 : (p - p / a) * inv(p % a, p) % p;
//}

// 费马小定理求逆元
int inv(int a, int p) {
    return qpow(a, p - 2, p);
}

int main() {
    //cout << niyuan(22, 5) << endl;
    
    //int x, y;
    //exgcd(22, 5, x, y);
    //cout << x << " " << y << endl;
 
    //cout << inv(22 % 5, 5) << endl;
    //cout << inv(22, 5) << endl;

    int x, y;
    int c = 3;	    // 求解ax + by = c;
    int d = exgcd(22, 5, x, y);	    // 求解22x + 5y = 3;
    if (c % d)
	cout << "no solution" << endl;
    else
	cout << c / d * x << " " << c / d * y << endl;

    return 0;
}
