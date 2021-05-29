#include <iostream>
#include <cmath>

using namespace std;

double pi = M_PI;

double helper(double r1, double r2, double r3) {
    double a = (r2 + r3) / 2, b = (r1 + r3) / 2, c = (r1 + r2) / 2;
    double len1 = (2 * pi - acos((a * a + b * b - c * c) / (2 * a * b)) * 2) * b;
    double len2 = (2 * pi - acos((a * a + c * c - b * b) / (2 * a * c)) * 2) * c;
    return (len1 + len2) / (pi * r1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	double r1, r2, r3;
	scanf("%lf %lf %lf", &r1, &r2, &r3);
	printf("%.15lf\n", min(min(helper(r1, r2, r3), helper(r2, r1, r3)), helper(r3, r1, r2)));
    }

    return 0;
}
