#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
	int arr[4] = {0, 0, 0, 1};
	for (int i = 2; i <= n; i++) {
	    arr[3] += arr[2];
	    arr[2] = arr[1];
	    arr[1] = arr[0];
	    arr[0] = arr[3];
	}
	cout << arr[0] + arr[1] + arr[2] + arr[3] << endl;
    }

    return 0;
}
