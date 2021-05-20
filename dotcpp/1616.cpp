#include <iostream>

using namespace std;

long long get_reverse(int val) {
    int rst = 0;
    while (val) {
	rst = rst * 10 + val % 10;
	val /= 10;
    }

    return rst;
}

int main() {
    long long a, b;
    cin >> a >> b;

    cout << get_reverse(get_reverse(a) + get_reverse(b)) << endl;

    return 0;
}
