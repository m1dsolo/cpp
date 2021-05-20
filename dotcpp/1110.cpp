// not meet the 200 bit condition

#include <iostream>
#include <cmath>

using namespace std;


long long C(long n, int m) {
    long long rst = 1;
    for (int i = n; i > (n - m); i--)
	rst *= i;
    for (int i = m; i > 1; i--)
	rst /= i;

    return rst;
}

int main() {
    int k, w;
    cin >> k >> w;
    
    int quo = w / k;
    int rem = w % k;
    long long rst = 0;
    // first digit is 0 and the following digit can be 0 too, but at least 2 digit is not 0.
    for (int i = 2; i <= quo; i++) {
	rst += C(w - 1, i);
    }

    // first digit from 1 to pow(2, rem)
    for (int i = 1; i < pow(2, rem); i++) {
	rst += C(w - i + 1, (rem) ? quo : quo - 1);
    }

    cout << rst << endl;

    return 0;
}
