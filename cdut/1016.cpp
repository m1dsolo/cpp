#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n, h, a;
    while (t--) {
	int arr[25] = {0};
	scanf("%d %d", &n, &h);
	for (int i = 0; i < n; i++) {
	    scanf("%d", &a);
	    arr[a] += 1;
	    arr[min(24, a + h)] -= 1;
	}
	int min_val = arr[0], index = 0;
	for (int i = 1; i < 24; i++) {
	    arr[i] += arr[i - 1];
	    if (arr[i] < min_val) {
		min_val = arr[i];
		index = i;
	    }
	}
	int ptr = index;
	while (ptr + 1 < 24 && arr[ptr + 1] == min_val)
	    ptr++;
	cout << index << " " << ptr << endl;
    }

    return 0;
}
