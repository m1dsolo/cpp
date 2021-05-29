// WA，贪心为什么不对？
#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	int n, a, b, rst = 0, tmp;
	scanf("%d %d %d", &n, &a, &b);
	if (a > b) swap(a, b);
	while (n) {
	    tmp = n / a * a;
	    if (!tmp) {
		rst += n;
		break;
	    }
	    rst += tmp;
	    n += n / a - tmp;
	    swap(a, b);
	}
	printf("%d\n", rst);
    }

    return 0;
}

