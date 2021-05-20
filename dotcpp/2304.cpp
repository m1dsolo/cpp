#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int rst = 0;
    for (int i = 1; i <= n; i++) {
	int val = i;
	while (val) {
	    int digit = val % 10;
	    if (digit == 2 || digit == 0 || digit == 1 || digit == 9) {
		rst += i;
		break;
	    }
	    val /= 10;
	}
    }
    cout << rst << endl;

    return 0;
}
