// longest increasing subsequence

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// //最长上升(<)子序列
//int lis(const vector<int> &v) {
    //int n = v.size();
    //vector<int> tail;
    //tail.emplace_back(v[0]);
    //for (int i = 1; i < n; i++) {
	//if (v[i] > tail.back())
	    //tail.emplace_back(v[i]);
	//else
	    //*lower_bound(tail.begin(), tail.end(), v[i]) = v[i];
    //}
    //return tail.size();
//}

int dp[100], pos[100];
void lis(const vector<int> &v) {
    const int n = v.size();
    dp[0] = v[0];
    int size = 1;
    for (int i = 1; i < n; i++) {
	if (v[i] > dp[size - 1]) {
	    pos[i] = size;
	    dp[size++] = v[i];
	}
	else {
	    int index = lower_bound(dp, dp + size, v[i]) - dp;
	    pos[i] = index;
	    dp[index] = v[i];
	}
    }

    cout << size << endl;

    int j = size - 1;
    for (int i = n - 1; i >= 0; i--) {
	if (j < 0) break;
	if (pos[i] == j)
	    dp[j--] = v[i];	    // 将dp变为rst
    }

    for (int i = 0; i < size; i++)
	cout << dp[i] << " ";
    cout << endl;
}

// 最长下降(>=)子序列
int lis_r(const vector<int> &v) {
    int n = v.size();
    vector<int> tail;
    tail.emplace_back(v[0]);
    for (int i = 1; i < n; i++) {
	if (v[i] <= tail.back())
	    tail.emplace_back(v[i]);
	else
	    *upper_bound(tail.begin(), tail.end(), v[i], greater<int>()) = v[i];
    }
    return tail.size();
}

int main() {
    vector<int> v{2, 4, 5, 3, 7};

    lis(v);

    return 0;
}
