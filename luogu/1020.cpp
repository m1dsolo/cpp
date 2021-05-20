#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
int main() {
    int n = 0;
    while (scanf("%d", &arr[n++]) != EOF); n--;

    // 最长下降(>=)子序列
    vector<int> tail;
    tail.emplace_back(arr[0]);
    for (int i = 1; i < n; i++) {
	if (arr[i] <= tail.back())
	    tail.emplace_back(arr[i]);
	else
	    *upper_bound(tail.begin(), tail.end(), arr[i], greater<int>()) = arr[i];
    }
    cout << tail.size() << endl;

    // 最长上升(<)子序列
    tail.clear();
    tail.emplace_back(arr[0]);
    for (int i = 1; i < n; i++) {
	if (arr[i] > tail.back())
	    tail.emplace_back(arr[i]);
	else
	    *lower_bound(tail.begin(), tail.end(), arr[i]) = arr[i];
    }
    cout << tail.size() << endl;

    return 0;
}
