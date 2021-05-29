#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int arr[N][N], tmp[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++)
	    scanf("%d", &arr[i][j]);
    }

    int q, x;
    scanf("%d", &q);
    int a = 0, b = 0;
    while (q--) {
	scanf("%d", &x);
	if (x == 1) a++;
	else b++;
    }

    if (a & 1) {
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++)
		tmp[i][j] = arr[n - 1 - i][n - 1 - j];
	}
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++)
		arr[i][j] = tmp[i][j];
	}
    }

    if (b & 1) {
	for (int i = n - 1; i >= 0; i--) {
	    for (int j = 0; j < n; j++)
		printf("%d ", arr[i][j]);
	    printf("\n");
	}
    }
    else {
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++)
		printf("%d ", arr[i][j]);
	    printf("\n");
	}
    }

    return 0;
}
