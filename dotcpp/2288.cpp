#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int f = 0;
    for (int i = 2; i <= n; i++) {
	f = (f + k) % i;
    }
    cout << f + 1 << endl;

    return 0;
}
