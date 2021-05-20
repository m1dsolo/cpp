#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++) 
	cin >> arr[i];
    int base = 2;
    int rst = 1;
    int level = 2;
    int max_val = arr[0];

    int index = 1;
    while (index < n) {
	int max_i = index + base;
	int tmp = 0;
	for (int i = 0; i < base && index < n; i++) {
	    tmp += arr[index++];
	}
	if (tmp > max_val) {
	    max_val = tmp;
	    rst = level;
	}
	level++;
	base *= 2;
    }
    cout << rst << endl;

    return 0;
}
