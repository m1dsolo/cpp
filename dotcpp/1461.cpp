#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string rst = "A";
    if (n == 1) {
	cout << rst << endl;
	return 0;
    }

    for (int i = 1; i < n; i++) {
	rst += char('A' + i) + rst;
    }

    cout << rst << endl;
    return 0;
}
