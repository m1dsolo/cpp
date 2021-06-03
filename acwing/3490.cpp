#include <iostream>

using namespace std;

int main() {
    int n, rst = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
	if ((i * i) % n < n / 2 + (n & 1)) rst++;
    }

    printf("%d\n", rst);
    
    return 0;
}
