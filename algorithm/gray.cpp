#include <iostream>
#include <bitset>

using namespace std;

int gray_to_dec(int a) {
    int b = a;
    while (a >>= 1)
	b ^= a;
    return b;
}

int dec_to_gray(int a) {
    return a ^ (a >> 1);
}

int main() {
    for (int i = 0; i <= 15; i++) {
	cout << bitset<4>(dec_to_gray(i)).to_string() << endl;
    }

    return 0;
}
