// 有三种物品，分别有3,2,3个，问拿出4个进行组合( [公式] 算一种 )的方案数是多少(完全背包)
#include <iostream>

using namespace std;

int main() {
    int dp[4][9] = {1};
    int v[3] = {3, 2, 3};
    for (int i = 1; i <= 3; i++) {
	for (int j = 0; j < 9; j++) {
	    for (int k = 0; k <= j; k++) {
		if (j - k <= v[i - 1])
		    dp[i][j] += dp[i - 1][k];	
	    }
	}
    }

    for (int j = 0; j <= 8; j++)
	cout << dp[3][j] << " ";
    cout << endl;

    return 0;
}
