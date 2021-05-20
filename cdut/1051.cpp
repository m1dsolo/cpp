#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int arr[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);

    int rst = 0;
    for (int i = n - 1; i >= 0; i--)
	rst = (rst + arr[i]) / 2 + (rst + arr[i]) % 2;

    printf("%d\n", rst);

    return 0;
}
