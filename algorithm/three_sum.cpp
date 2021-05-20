#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> three_sum(vector<int> nums) {
    vector<vector<int>> rst;
    if (nums.size() < 3) return rst;
    sort(nums.begin(), nums.end());
    
    int i = 0;
    while (i < nums.size() && nums[i] <= 0) {
	int left = i + 1, right = nums.size() - 1;
	while (left < right) {
	    int sum = nums[i] + nums[left] + nums[right];
	    if (!sum) {
		rst.push_back(vector<int> {nums[i], nums[left], nums[right]});
		left++; right--;
		while (left < nums.size() && nums[left] == nums[left - 1]) left++;
		while (right >= 0 && nums[right] == nums[right + 1]) right--;
	    }
	    else if (sum < 0)
		left++;
	    else if (sum > 0)
		right--;
	}

	i++;
	while (i < nums.size() && nums[i] == nums[i - 1])
	    i++;
    }

    return rst;
}

int main() {
    vector<vector<int>> vv = three_sum(vector<int> {0, 0, 0});

    for (int i = 0; i < vv.size(); i++) {
	for (int j = 0; j < vv[0].size(); j++)
	    cout << vv[i][j] << " ";
	cout << endl;
    }

    return 0;
}
