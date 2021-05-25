#include <iostream>
#include <climits>

using namespace std;

const int N = 1e4 + 10;

int main() {
    int n, m, k, a, b;
    scanf("%d %d %d", &n, &m, &k);
    double p1 = (double)m / n;
    double p2 = 1 - p1;
    double max_val = INT_MIN;
    int index = 0;
    for (int i = 0; i < k; i++) {
	scanf("%d %d", &a, &b);
	double e = p1 * a + p2 * b;
	if (e >= max_val) {
	    max_val = e;
	    index = i;
	}
    }

    for (int i = 0; i < index; i++)
	printf("0 ");
    printf("%d", n);
    for (int i = index + 1; i < k; i++)
	printf(" 0");
    printf("\n");

    return 0;
}
