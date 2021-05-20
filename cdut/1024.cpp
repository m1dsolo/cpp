#include <iostream>

using namespace std;

int main() {
    int a, b, mod = 26;
    scanf("%d %d", &a, &b);
    char c;
    getchar();
    while (scanf("%c", &c) != EOF) {
	if (isalpha(c))
	    printf("%c", ((long long)a * (c - 'a') + b) % mod + 'a');
    }
    printf("\n");

    return 0;
}
