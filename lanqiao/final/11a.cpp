#include <iostream>

using namespace std;

bool helper(int n) {
    while (n) {
	if (n % 10 == 2) return true;
	n /= 10;	
    }
    return false;
}

int main() {
    int rst = 0;
    for (int i = 1; i <= 2020; i++) {
	rst += helper(i);
    }

    cout << rst << endl;

    return 0;
}
