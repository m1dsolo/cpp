#include <iostream>

using namespace std;

int main() {
    int n, a, b = 2e9, rst = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d", &a);
	rst += max(0, a - b);
	b = a;
    }

    printf("%d\n", rst);

    return 0;
}
