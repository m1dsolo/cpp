#include <iostream>

using namespace std;

int n, a, b;
int helper(int x, int y) {
    int rst = 0;
    while (1) {
	int tmp1 = x / a;
	int tmp2 = y / b;
	if (!tmp1 && !tmp2) {
	    rst += x + y;
	    break;
	}
	x += tmp2 - tmp1 * a;
	y += tmp1 - tmp2 * b;
	rst += tmp1 * a + tmp2 * b;
    }
    return rst;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d %d", &n, &a, &b);
	int rst = 0;
	for (int i = 0; i <= n; i++)
	    rst = max(rst, helper(i, n - i));
	printf("%d\n", rst);
    }

    return 0;
}
