// why cant rst %= 10 ???
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int rst = 1;
    for (int i = 2; i <= n; i++) {
	rst *= i;
	while (!(rst % 10)) rst /= 10;
	rst %= 1000000;
    }

    cout << rst % 10 << endl;

    return 0;
}
