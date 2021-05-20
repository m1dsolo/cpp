#include <iostream>

using namespace std;

const int N = 1e4 + 10;

long long arr[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%lld", &arr[i]);
    long long dp = -1, rst = -1, l = arr[0], r = arr[n - 1];
    for (int i = 0; i < n; i++) {
	if (max(dp + arr[i], arr[i]) > rst) {
	    if (arr[i] > dp + arr[i])
		l = arr[i];
	    r = arr[i];
	}
	rst = max(rst, dp = max(dp + arr[i], arr[i]));
    }

    cout << max(rst, 0ll) << " " << l << " " << r << endl;

    return 0;
}
