#include <iostream>

using namespace std;

int main() {
    int n, rst = 0;
    scanf("%d", &n);
    while (n) {
	int a = n / 3;
	if (!a) {
	    rst += n;
	    break;
	}
	rst += a * 3;
	n -= 2 * a;
    }

    printf("%d\n", rst);

    return 0;
}
