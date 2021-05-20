#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;
    int i = 2, max_i = sqrt(n);
    for (; i <= max_i; i++) {
	if (!(n % i)) break;
    }

    cout << (i == max_i + 1 ? n : i) << endl;

    return 0;
}
