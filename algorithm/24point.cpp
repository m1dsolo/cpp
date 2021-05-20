#include <iostream>
#include <vector>

using namespace std;

vector<double> get_nums(const vector<double> &nums, double val) {
    vector<double> v(nums);
    v.push_back(val);
    return v;
}

bool dfs(const vector<double> &nums) {
    int n = nums.size();
    if (n == 1)
	return abs(nums.front() - 24) < 1e-6;
    for (int i = 0; i < n; i++) {
	for (int j = i + 1; j < n; j++) {
	    vector<double> v;
	    for (int k = 0; k < n; k++) {
		if (k != i && k != j)
		    v.push_back(nums[k]);
	    }
	    if (dfs(get_nums(v, nums[i] + nums[j]))) return true;
	    if (dfs(get_nums(v, nums[i] - nums[j]))) return true;
	    if (dfs(get_nums(v, nums[j] - nums[i]))) return true;
	    if (dfs(get_nums(v, nums[i] * nums[j]))) return true;
	    if (dfs(get_nums(v, nums[i] / nums[j]))) return true;
	    if (dfs(get_nums(v, nums[j] / nums[i]))) return true;
	}
    }
    return false;
}

int main() {
    vector<double> nums(4);
    for (int i = 0; i < 4; i++)
	cin >> nums[i];
    cout << dfs(nums) << endl;

    return 0;
}
