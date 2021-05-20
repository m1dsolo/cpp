#include <iostream>

using namespace std;

int n;
int arr[102], dp1[102], dp2[102];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
	cin >> arr[i];

    for (int i = 1; i <= n; i++) {
	for (int j = 0; j <= i; j++) {
	    if (arr[i] > arr[j])
		dp1[i] = max(dp1[i], dp1[j] + 1);
	}
    }

    for (int i = n; i >= 1; i--) {
	for (int j = n + 1; j >= i; j--) {
	    if (arr[i] > arr[j])
		dp2[i] = max(dp2[i], dp2[j] + 1);
	}
    }

    int rst = 0;
    for (int i = 1; i <= n; i++) {
	rst = max(rst, dp1[i] + dp2[i] - 1);
    }

    cout << n - rst << endl;

    return 0;
}
