#include <iostream>

using namespace std;

const int N = 1e7;

int arr[N];

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++)
	scanf("%d\n", &arr[i]);

    int l = 1, r = 1, sum = 0, min_len = 2e7, rst;
    while (r <= n) {
	sum += arr[r++];
	while (sum >= x) {
	    if (r - l < min_len) {
		min_len = r - l;
		rst = l;
	    }
	    sum -= arr[l++];
	}
    }

    printf("%d %d\n", rst, rst + min_len - 1);

    return 0;
}
