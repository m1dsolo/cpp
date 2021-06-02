#include <iostream>

using namespace std;

int main() {
    int n, x, y, a = 0, b = 0;
    scanf("%d%d", &n, &x);
    bool flag = x > 0;
    for (int i = 1; i < n; i++) {
	scanf("%d", &y);
	if (y > 0 && y < abs(x)) a++;
	if (y < 0 && -y > abs(x)) b++;
    }

    printf("%d\n", !flag && !a || flag && !b ? 1 : a + b + 1);

    return 0;
}
