#include <iostream>

using namespace std;

int helper(int n) {
    switch (n) {
	case 1: return 1;
	case 2: return 2;
	case 3: return 6;
    }
    return n * (n - 1) / (n - 2) - (n - 3);
}

int main() {
    int n = 10;

    if (n < 4)
	return helper(n);

    int rst = n * (n - 1) / (n - 2) + (n - 3); n -= 4;
    while (n >= 4) {
	rst -= helper(n);
	n -= 4;
	cout << n << " " << rst << endl;
    }

    cout << rst - helper(n) << endl;

    return 0;
}
