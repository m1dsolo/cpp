#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    int i = left, j = right + 1;
    while (true) {
	while (nums[++i] < pivot) {
	    if (i == right) break;
	}
	while (nums[--j] > pivot) {
	    if (j == left) break;
	}
	if (i >= j) break;
	swap(nums[i], nums[j]);
    }
    swap(nums[j], nums[left]);

    return j;
}

void qsort(vector<int> &nums, int left, int right) {
    if (left >= right) return;

    int mid = partition(nums, left, right);

    qsort(nums, left, mid - 1);
    qsort(nums, mid + 1, right);
}

void qsort(vector<int> &nums) {
    qsort(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums{1, 5, 4, 2, 3};
    qsort(nums);

    for (int num : nums) {
	cout << num << " ";
    }
    cout << endl;

    return 0;
}
