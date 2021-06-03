#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int arr[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);
    sort(arr, arr + n);

    int a = 0;
    for (int i = 1; i < n; i++)
	a = gcd(a, arr[i] - arr[i - 1]);
    printf("%d\n", a ? (arr[n - 1] - arr[0]) / a + 1 : n);	// 注意特判0!!!

    return 0;
}
