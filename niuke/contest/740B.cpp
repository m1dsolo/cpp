#include <iostream>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int rst = n;
    for (int i = 1; i < m; i++)
	rst = (rst * (n - 1)) % 109;

    printf("%d\n", rst);

    return 0;
}
