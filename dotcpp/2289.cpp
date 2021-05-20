#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long pre = 1, cur = 2;
    long long base = 2;
    long long digit = 1;
    while (cur <= n) {
	pre = cur;
	cur += base * base;
	digit += (base++ - 1);
    }
    //cout << pre << " " << digit << ' ' << base << endl;
    cout << digit + (n - pre) / (base - 1) << endl;


    return 0;
}
