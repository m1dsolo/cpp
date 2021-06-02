#include <iostream>

using namespace std;

int main() {
    int n = 30;
    int dp0 = 1, dp1 = 0;
    for (int i = 0; i < n; i++) {
	int t0 = dp0 + dp1, t1 = dp0;
	dp0 = t0, dp1 = t1;
    }

    printf("%d\n", dp0 + dp1);

    return 0;
}
