#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


int get_gcd(int a, int b) {
    return b ? get_gcd(b, a % b) : a;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++)
	scanf("%d", &nums[i]);
    sort(nums, nums + n);
    int d = 0;

    for (int i = 1; i < n; i++) {
	d = get_gcd(d, nums[i] - nums[i - 1]);
    }

    cout << (d ? (nums[n - 1] - nums[0]) / d + 1 : n) << endl;

    return 0;
}
