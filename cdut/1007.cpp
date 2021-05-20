#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
	printf("%.6lf\n", sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2)));
    }

    return 0;
}
