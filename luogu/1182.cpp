#include <iostream>

using namespace std;

int n, m;
int arr[100001];

int get_m(int max_cap) {
    int rst = 1;
    int cap = 0;
    for (int i = 1; i <= n; i++) {
	if (cap + arr[i] > max_cap) {
	    rst++;
	    cap = 0;
	}
	cap += arr[i];
    }
    return rst;
}

int main() {
    cin >> n >> m;
    int left = 0, right = 0;
    for (int i = 1; i <= n; i++) {
	scanf("%d", &arr[i]);
	left = max((int)left, arr[i]);
	right += arr[i];
    }

    // 要求最大值的最小，最小就是求右边界，有if( <= ) left = mid + 1,又因为相反，所以if内变号
    while (left <= right) {
	int mid = left + (right - left) / 2;
	if (get_m(mid) > m)
	    left = mid + 1;
	else
	    right = mid - 1;
    }

    cout << left << endl;

    return 0;
}
