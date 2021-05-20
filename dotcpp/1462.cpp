// i think the time complexity is too high
#include <iostream>
#include <algorithm>

using namespace std;

//bool compare(int a, int b) {
    //return a > b;
//}

int main() {
    int n;
    cin >> n;
    int arr[n];
    int len = n;
    for (int i = 0; i < n; i++) {
	cin >> arr[i];
    }

    int rst = 0;
    while (len > 1) {
	//sort(arr, arr + len, compare)
	sort(arr, arr + len, [] (int a, int b) -> bool { return a > b; });
	int val = arr[len - 2] + arr[len - 1];
	rst += val;
	arr[len - 2] = val;

	len--;
    }

    cout << rst << endl;

    return 0;
}
