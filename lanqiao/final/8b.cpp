#include <iostream>

using namespace std;

int popcnt(int n) {
    int rst = 0;
    while (n) {
	if (n & 1) rst++;
	n >>= 1;
    }
    return rst;
}

bool is_ok(int n) {
    if (popcnt(n) & 1) return false;

}

int main() {
    for (int i = 0; i < (1 << 30); i++) {
    }

    return 0;
}
