#include <iostream>

using namespace std;

long long MIN = 10000, MAX = 6227020800;

long long factorial(long long a) {
    if (a == 1) return 1;
    return a * factorial(a - 1);
}

int main() {
    long long a;
    while (scanf("%lld", &a) != EOF) {
	if (a >= 15) printf("Overflow!\n");	
	else if (a <= 0) printf("Underflow!\n");
	else {
	    long long rst = factorial(a);
	    if (rst > MAX) printf("Overflow!\n");
	    else if (rst < MIN) printf("Underflow\n");
	    else printf("%lld\n", rst);
	}
    }

    return 0;
}
