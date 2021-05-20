#include <iostream>

using namespace std;

int arr[1001][2];
long long dp[1001];
int main() {
    int n, x, a, b;
    cin >> n >> x;
    long long rst = 0;
    for (int i = 0; i < n; i++) {
	scanf("%d %d %d", &a, &b, &arr[i][1]);
	arr[i][0] = b - a;
	rst += a;
    }


    for (int i = 0; i < n; i++) {
	for (int j = x; j >= arr[i][1]; j--) {
	    dp[j] = max(dp[j], dp[j - arr[i][1]] + arr[i][0]);
	}
    }

    cout << (rst + dp[x]) * 5 << endl;

    return 0;
}
