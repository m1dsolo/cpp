#include <iostream>

using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;

    long long rst = 0;
    long long val = 1;
    long long step = 1;
    for (int i = 0; i < t; i++) {
	rst += val;
	val = (val + (2 * step + n - 1) * n / 2) % k;
	step += n;
    }

    cout << rst << endl;

    return 0; 
}
