#include <iostream>

using namespace std;

const int k = 2;

int main() {
    int n;
    scanf("%d", &n);
    int rst = 0;
    for (int i = 2; i <= n; i++) {
	int num = min((i - 1 - rst) / k, n - i);
	i += num;
	rst = (rst + k * (num + 1)) % i;
    }

    printf("%d\n", rst + 1);

    return 0;
}
