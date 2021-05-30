#include <iostream>

using namespace std;

int main() {
    double a, b, c;
    double rst = 0.65;
    for (int i = 0; i < 3; i++) {
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a >= max(b, c)) {
	    cout << 'W' << " ";
	    rst *= a;
	}
	else if (b >= c) {
	    cout << 'T' << " ";
	    rst *= b;
	}
	else {
	    cout << 'L' << " ";
	    rst *= c;
	}
    }

    printf("%.2lf\n", (rst - 1) * 2);

    return 0;
}
