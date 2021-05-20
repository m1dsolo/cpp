// 没去重
// 2 4 8 10是答案最多的(10个)
// 3 3 7 7, 3 3 8 8有分数

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> set;

vector<double> get_nums(const vector<double> &nums, double val) {
    vector<double> v(nums);
    v.push_back(val);
    return v;
}

string get_s(const string &s, double a, double b, char c) {
    return s + to_string(a) + c + to_string(b) + ' ';
}

void dfs(const vector<double> &nums, const string &s) {
    int n = nums.size();
    if (n == 1) {
	if (abs(nums.front() - 24) < 1e-6)
	    set.insert(s);
	return;
    }
    for (int i = 0; i < n; i++) {
	for (int j = i + 1; j < n; j++) {
	    vector<double> v;
	    for (int k = 0; k < n; k++) {
		if (k != i && k != j)
		    v.push_back(nums[k]);
	    }
	    dfs(get_nums(v, nums[i] + nums[j]), get_s(s, nums[i], nums[j], '+'));
	    dfs(get_nums(v, nums[i] - nums[j]), get_s(s, nums[i], nums[j], '-'));
	    dfs(get_nums(v, nums[j] - nums[i]), get_s(s, nums[j], nums[i], '-'));
	    dfs(get_nums(v, nums[i] * nums[j]), get_s(s, nums[i], nums[j], '*'));
	    dfs(get_nums(v, nums[i] / nums[j]), get_s(s, nums[i], nums[j], '/'));
	    dfs(get_nums(v, nums[j] / nums[i]), get_s(s, nums[j], nums[i], '/'));
	}
    }
}

int main() {
    vector<double> nums(4);
    for (int i = 0; i < 4; i++)
	cin >> nums[i];
    dfs(nums, "");

    for (const string &s : set)
	cout << s << endl;
    cout << set.size() << endl;

    return 0;
}
