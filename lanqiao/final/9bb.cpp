#include <iostream>

using namespace std;

int main() {
    int rst = 0;
    for (int i = 1; i <= 1 << 30; i++) {
	bool flag = true;
	for (int j = 0; j < 30; j++) {
	    if ((i >> j & 1) && (i >> (j - 1) & 1)) {
		flag = false;
		break;
	    }
	}
	rst += flag;
    }

    printf("%d\n", rst);

    return 0;
}
