#include <iostream>
#include <algorithm>

using namespace std;

const int size = 1000000;
int arr[3][size];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
	for (int j = 0; j < n; j++) {
	    scanf("%d", &arr[i][j]);
	}
    }
    sort(arr[0], arr[0] + n);
    sort(arr[1], arr[1] + n);
    sort(arr[2], arr[2] + n);

    long long rst = 0;
    for (int i = 0; i < n; i++) {
	long long x = lower_bound(arr[0], arr[0] + n, arr[1][i]) - arr[0];
	long long y = (n - (upper_bound(arr[2], arr[2] + n, arr[1][i]) - arr[2]));
	rst += x * y;
    }
    cout << rst << endl;

    return 0;
}
