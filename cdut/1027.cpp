#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e3 + 10;
pair<double, double> points[N];

int main() {
    int n, o;
    scanf("%d %d", &n, &o);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
	scanf("%lf", &points[i].second);
	points[i].second += points[i - 1].second;
    }

    int a, b;
    while (o--) {
	scanf("%d %d", &a, &b);
	double x2 = points[a].first, y2 = points[a].second;
	for (int i = a + 1; i <= n; i++) {
	    double x1 = points[i].first, y1 = points[i].second;
	    points[i].first = (x1 - x2) * cos(M_PI * b / 180) - (y1 - y2) * sin(M_PI * b / 180) + x2;
	    points[i].second = (y1 - y2) * cos(M_PI * b / 180) + (x1 - x2) * sin(M_PI * b / 180) + y2;
	}
	printf("%.2lf %.2lf\n", points[n].first, points[n].second);
    }

    return 0;
}
