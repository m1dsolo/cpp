// dfs and dp(knapsack problem)
// timeout, but i dont know why

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, k, rst = 0;
vector<int> stamps;
vector<int> design;

int dp() {
    vector<int> dp(n * stamps.back() + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < dp.size(); i++) {
	for (int j = 0; j < stamps.size(); j++) {
	    int index = i - stamps[j];
	    if (index >= 0) 
		dp[i] = min(dp[i], dp[index] + 1);
	}

	if (dp[i] > n) 
	    return i - 1;
    }

    return dp.size() - 1;
}

void dfs() {
    if (stamps.size() == k) {
	int tmp = dp();
	if (tmp > rst) {
	    rst = tmp;
	    design = stamps;
	}
	return;
    }

    int max_i = n * stamps.back() + 1;
    for (int i = stamps.back() + 1; i <= max_i; i++) {
	stamps.push_back(i);
	dfs();
	stamps.pop_back();
    }
}

int main() {
    cin >> n >> k;

    stamps.reserve(k);
    stamps.push_back(1);
    dfs();

    for (int i = 0; i < design.size(); i++)
	cout << design[i] << " ";
    cout << endl << "MAX=" << rst << endl;

    return 0;
}
