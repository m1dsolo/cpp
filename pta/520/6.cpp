#include <iostream>

using namespace std;

int arr[110][110];
int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++)
	    scanf("%d", &arr[i][j]);
    }

    int tmp = 1;
    for (int j = 1; j < n; j += 2) {
	int i = n - 1;
	for (;i >= tmp; i--) {
	    arr[i][j] = arr[i - tmp][j]; 
	}
	while (i >= 0)
	    arr[i--][j] = x;
	tmp = tmp % k + 1;
    }

    for (int i = 0; i < n - 1; i++) {
	int sum = 0;
	for (int j = 0; j < n; j++)
	    sum += arr[i][j];
	printf("%d ", sum);
    }
    int sum = 0;
    for (int j = 0; j < n; j++)
	sum += arr[n - 1][j];
    printf("%d\n", sum);

    return 0;
}
