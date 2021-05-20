#include <iostream>

using namespace std;

int count_one(int n) {
    int cnt = 0;
    while (n) {
	n = n & (n - 1);
	cnt++;
    }

    return cnt;
}

int main() {
    const unsigned char seg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 
			0x92, 0x82, 0xf8, 0x80, 0x90};	    // anode

    int len;
    cin >> len;
    string s0, s1;
    cin >> s0 >> s1;

    int rst = 0;
    for (int i = 0; i < len; i++) {
	rst += count_one(seg[s0[i] - '0'] ^ seg[s1[i] - '0']);
    }

    cout << rst << endl;
}
