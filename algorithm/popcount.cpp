#include <iostream>

using namespace std;

int table[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
int popcount(unsigned int x) { // 返回x的二进制中1的个数
    int ret = 0;
    for(int i = 0; i < 8; i++) ret += table[x & 15], x >>= 4;
    return ret;
}

int main() {
    for (int i = 1; i <= 10; i++)
	cout << popcount(i) << endl;

    return 0;
}
