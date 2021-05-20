#include <iostream>

using namespace std;

int main() {
    int y = 2021;
    int a = 2019 * 2019;
    bool flag = false;
    int x = 2020;
    while (1) {
	int c = y * y;
	for (x = 2020; x < y; x++) {
	    int b = x * x;
	    if (c - b == b - a) {
		flag = true;
		break;
	    }
	}
	if (flag) break;
	y++;
    }

    cout << x << " " << y << endl;

    return 0;
}
