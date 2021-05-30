#include <iostream>

using namespace std;

int main() {
    int n, a = 0, b = 0, pre = 0, cur, diff;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d", &cur);
	diff = cur - pre;
	if (diff >= 0) a += diff;
	else b -= diff;
	pre = cur;
    }

    cout << a * 6 + b * 4 + n * 5 << endl;

    return 0;
}
