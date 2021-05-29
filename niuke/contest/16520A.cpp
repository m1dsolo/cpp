#include <iostream>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

ll arr[N];

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	ll sum = 0, rst1 = 0, rst2 = 0;
	for (int i = 0; i < n; i++) {
	    scanf("%lld", &arr[i]);
	    sum += arr[i];
	    rst1 += arr[i] * (n - i);
	    rst2 += arr[i] * (i + 1);
	}
	ll tmp = rst1;
	for (int i = 1; i < n; i++)
	    rst1 = min(rst1, tmp += sum - arr[i - 1] * n);
	tmp = rst2;
	for (int i = n - 2; i >= 0; i--)
	    rst2 = min(rst2, tmp += sum - arr[i + 1] * n);
	printf("%lld\n", min(rst1, rst2));
    }

    return 0;
}
