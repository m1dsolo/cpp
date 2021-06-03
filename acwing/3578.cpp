#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int arr[N], v[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);
    sort(arr, arr + n);
    for (int i = n / 2 + 1; i < n; i++)
	v[i] = (arr[i] - arr[i - 1]) * (i - n / 2);

    int i;
    for (i = n / 2; i < n && k >= v[i]; i++)
	k -= v[i];

    printf("%d\n", arr[i - 1] + k / (i - n / 2));

    return 0;
}
