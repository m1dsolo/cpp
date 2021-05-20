#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x1 = 0, y1 = 15, x2 = 0, y2 = 0, theta = 90;
    double x = (x1 - x2) * cos(M_PI * theta / 180) - (y1 - y2) * sin(M_PI * theta / 180) + x2;
    double y = (y1 - y2) * cos(M_PI * theta / 180) + (x1 - x2) * sin(M_PI * theta / 180) + y2;

    printf("%.2lf %.2lf\n", x, y);

    return 0;
}
