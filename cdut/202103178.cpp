#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;
int arr[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);
    sort(arr, arr + n);

    int rst = arr[0];
    for (int i = 1; i < n; i++)
	rst = (rst + arr[i]) / 2;

    cout << rst << endl;

    return 0;
}
