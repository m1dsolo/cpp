#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n, a, dp = 0, rst = INT_MIN;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf("%d", &a);
	dp = max(dp + a, a);
	rst = max(rst, dp);
    }

    cout << rst << endl;

    return 0;
}
