#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    double x, y, d;
    while (t--) {
	scanf("%lf %lf %lf", &x, &y, &d);
	printf("%.6lf\n", y * d / (2 * x));
    }

    return 0;
}
