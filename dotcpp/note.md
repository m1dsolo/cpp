1427: a, b cant compose min val: a * b - a - b
1445: hard dp(3 for)
1446: gcd lcm
1454: ant(clever)
#define hh ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
1493: calendar
1557: classic dp
1560: seg, clever count_bit()
1576: dfs and dp(knapsack problem)

binary search: find mid:(for not need to distinguish odd and even) set len m and n, val_mid = (val[(m + n + 1) / 2] + val[(m + n + 2) / 2]);


sliding window: deque


!!! remember cin cout method(1572: setiosflags(ios::uppercase), hex, dec, oct...)
			    (1597: setiosflags(ios::fixed), setprecision()..., 
			    cout << setw(2) << setfill('0') << val, 不足2位用0补齐)


while (getline(stringstream, string, ',')) use to split string

O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n^3) < O(2^n)< O(!n)

其中 O(!n)与O(2^n)被称为非多项式级时间复杂度，增长速度大于且远远大于前面的多项式级时间复杂度。

dp:
最大上升子序列：
// 以nums[i]为结尾的最大上升子序列
for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
	if (nums[i] > nums[j])
	    dp[i] = max(dp[i], dp[j] + 1);
	rst = max(rst, dp[i]);
    }
}

最大子数组和:
// 以nums[i]为结尾的最大子数组和
for (int i = 0; i < nums.size(); i++) {
    dp[i] = max(dp[i] + nums[i], nums[i]);
    rst = max(rst, dp[i]);
}

最长公共子序列
// 以nums[i]和nums[j]结尾的最长公共子序列
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
	if (s1[i - 1] == s2[j - 1])
	    dp[i][j] = dp[i - 1][j - 1] + 1;
	else
	    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
}


stringstream:
while (getline(ss, string, "_")) 可以用来分割字符串

将a向上取整至b的算法: rst = (a + b - 1) / b * b;

joseph ring:一行递归,还是用迭代把（省内存）:
f(n, k) {
    int rst = 0;
    for (int i = 2; i <= n; i++) {
	rst = (rst + k) % i;
    }
    return rst + 1; 
}

gcd一行递归记着(lcm)

<algorithm>
nth_element(v.begin(), v.begin() + k, v.end(), []()->bool {});

bfs: leetcode经典bfs

m,n最大不能凑出来的数：m * n - m - n;
