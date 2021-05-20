#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e6;
int arr[N + 10];

int main() {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d", &a);
	int max_j = sqrt(a);
	for (int j = 1; j <= max_j; j++) {
	    if (!(a % j)) {
		arr[j]++;
		arr[a / j]++;
	    }
	}
	if (max_j * max_j == a)
	    arr[max_j]--;
    }

    int ptr = N;
    for (int i = 1; i <= n; i++) {
	while (arr[ptr] < i) ptr--;
	printf("%d\n", ptr);
    }

    return 0;
}
