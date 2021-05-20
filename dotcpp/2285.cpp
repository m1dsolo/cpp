#include <iostream>

using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    long long rst;

    // one
    if (x >= 0 && y >= 0) {
	long long n = max(x, y);
	rst = 4 * n * n - (n - x) + (n - y);
    }
    // two
    else if (x > 0 && y < 0) {
	long long n = max(x, abs(y));
	rst = 4 * n * n + 2 * n + (n - x) - (y - n) ;
    }
    // three
    else if (x <= 0 && y <= 0) {
	long long n = max(abs(x), abs(y));
	rst = (2 * n - 1) * (2 * n - 1) - (x - n) + (y - n);
    }
    // four
    else if (x < 0 && y > 0) {
	long long n = max(abs(x), y);
	rst = 4 * n * n - 2 * n + (x - n) - (n - y);
    }

    cout << rst << endl;

    return 0;
}
