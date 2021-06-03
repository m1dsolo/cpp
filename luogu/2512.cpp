#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 1e6 + 10;

int arr[N];
ll c[N];

int main() {
    int n;
    ll avg = 0, rst = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf("%d", &arr[i]);
	avg += arr[i];
    }
    avg /= n;
    for (int i = 1; i <= n; i++)
	c[i] = c[i - 1] + arr[i] - avg;

    nth_element(c + 1, c + 1 + n / 2, c + 1 + n);
    ll mid = c[n / 2 + 1];
    for (int i = 1; i <= n; i++)
	rst += abs(mid - c[i]);

    printf("%lld\n", rst);

    return 0;
}
