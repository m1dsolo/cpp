#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    set<double> s;
    // double一定可以保证15位精度
    // double 11位阶码 52位尾数(2 ** 52 - 1 == 4503599627370495)为16位数字，即只能最多保证15位精度
    // float 8位阶码 23位尾数(2 ** 23 - 1 == 8388607)为7位数字，即只能最多保证6位精度
    for (int i = 0; i < 100000; i++) {
	s.insert((double)1 + 1e-15 * i);
    }
    cout << s.size() << endl;
    s.clear();
    for (int i = 0; i < 100000; i++) {
	s.insert((double)1 + 1e-16 * i);
    }
    cout << s.size() << endl;

    return 0;
}
