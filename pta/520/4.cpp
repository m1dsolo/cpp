#include <iostream>

using namespace std;

bool helper(int n, int d) {
    while (n) {
	if (n % 10 == d) return true;
	n /= 10;
    }
    return false;
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    int rst = n;
    for (int i = 1; i < n; i++) {
	if (helper(i, d)) rst--;
    }

    cout << rst << endl;

    return 0;
}
