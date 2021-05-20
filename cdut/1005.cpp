#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
	if (n < 2) printf("-1");
	else {
	    if (n % 2) {
		printf("7");
		n -= 3;
	    }
	    for (int i = 0; i < n / 2; i++) {
		printf("1");
	    }
	}
	printf("\n");
    }

    return 0;
}
