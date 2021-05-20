#include <iostream>
#include <iomanip>

using namespace std;

const double deviation = 1e-8;

int main() {
    int n;
    cin >> n;
    if (n > 100) {
	printf("%.8lf\n", 0.61803399);
	return 0;
    }
    double pre = 1;
    double cur = 1;
    double pre_double = 1;
    for (int i = 2; i <= n; i++) {
	double val = pre + cur;
	double cur_double = (double)cur / val;
	pre_double = cur_double;
	pre = cur;
	cur = val;
    }
    printf("%.8lf\n", pre_double);

    return 0;
}
