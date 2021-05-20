#include <iostream>

using namespace std;

const int N = 1e4 + 10;

int arr[N][4];

int main() {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	for (int j = 0; j < 4; j++)
	    scanf("%d", &arr[i][j]);
    }
    scanf("%d %d", &x, &y);

    int i = n;
    for (; i >= 1; i--) {
	if (x >= arr[i][0] && x <= arr[i][0] + arr[i][2] && y >= arr[i][1] && y <= arr[i][1] + arr[i][3]) {
	    cout << i << endl;
	    break;
	}
    }
    if (!i)
	cout << -1 << endl;

    return 0;
}
