#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int arr[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);
    nth_element(arr, arr + n / 2, arr + n);
    int mid = arr[n / 2];

    ll rst = 0;
    for (int i = 0; i < n; i++)
	rst += abs(mid - arr[i]);

    printf("%lld\n", rst);

    return 0;
}
