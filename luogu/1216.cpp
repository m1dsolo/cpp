#include <iostream>

using namespace std;

int arr[1002];
int main() {
    int r, a, rst = 0;
    scanf("%d", &r);
    for (int i = 1; i <= r; i++) {
	for (int j = i; j >= 1; j--) {
	    scanf("%d", &a);
	    arr[j] = max(arr[j], arr[j - 1]) + a;
	    rst = max(rst, arr[j]);
	}
    }

    cout << rst << endl;

    return 0;
}
