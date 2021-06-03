#include <iostream>

using namespace std;

const int N = 110;

int arr[N];

int main() {
    int n, sum = 0, rst = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
	sum += arr[i];
    }
    sum /= n;

    for (int i = 0; i < n; i++)
	if (arr[i] - sum) arr[i + 1] += arr[i] - sum, rst++;

    printf("%d\n", rst);

    return 0;
}
