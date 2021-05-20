#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr1[100001], arr2[100001], dp[100001], m[100001];

int lis() {
    vector<int> tail;
    tail.emplace_back(arr2[1]);
    for (int i = 2; i <= n; i++) {
	if (arr2[i] > tail.back())
	    tail.emplace_back(arr2[i]);
	else
	    *lower_bound(tail.begin(), tail.end(), arr2[i]) = arr2[i];
    }
    return tail.size();
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf("%d", &arr1[i]);
	m[arr1[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
	scanf("%d", &arr2[i]);
	arr2[i] = m[arr2[i]];
    }

    cout << lis() << endl;


    return 0;
}
