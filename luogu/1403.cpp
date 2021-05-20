#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int rst = 0;
    for (int i = 1; i <= n; i++)
	rst += n / i;

    cout << rst << endl;

    return 0;
}
