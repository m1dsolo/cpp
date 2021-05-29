// poj 3666是26->1e9的扩大版，但是1e9可以映射到下标，所以复杂度为min(O(n ** 2), O(n * m)), m是字符取值范围
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

char s[N], s2[N];
int dp[26];	    // 滚动数组dp[i][j]：前i + 1个数以j结尾的最优解

int main() {
    int n;
    scanf("%d%s", &n, &s);
    memcpy(s2, s, n);

    int min_val;
    for (int i = 0; i < n; i++) {
	min_val = 2e9;
	for (char c = 'A'; c <= 'Z'; c++) {
	    min_val = min(min_val, dp[c - 'A']);	// 统计下dp[i - 1][0 ~ c]的最小值
	    dp[c - 'A'] = min_val + abs(c - s[i]);
	}
    }

    int rst = 2e9;
    for (int i = 0; i < 26; i++)    // 结尾在哪不一定
	rst = min(rst, dp[i]);

    printf("%d\n", rst);

    return 0;
}
