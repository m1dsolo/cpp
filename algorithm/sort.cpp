#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef enum {
    BUBBLE, 
    COUNTING, 
    QUICK
} SORT_TYPE;

class Sort {
private:
    void bubble_sort(vector<int> &nums);
    void counting_sort(vector<int> &nums);
    void qsort(vector<int> &nums);

    void qsort(int left, int right, vector<int> &nums);
    int partition(int left, int right, vector<int> &nums);
public:
    Sort() {};
    void sort(vector<int> &nums, SORT_TYPE type) {
	switch (type) {
	    case BUBBLE: bubble_sort(nums); break;
	    case COUNTING: counting_sort(nums); break;
	    case QUICK: qsort(nums); break;
	 }
    };
    void print(vector<int> &nums) {
	for (int num : nums) 
	    cout << num << " ";
	cout << endl;
    };
};

// 值大的放右边, O(n ** 2)
void Sort::bubble_sort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n - 1 - i; j++) {
	    if (nums[j] > nums[j + 1])
		swap(nums[j], nums[j + 1]);
	}
    }
}

void Sort::counting_sort(vector<int> &nums) {
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    for (int num : nums) {
	max_val = max(max_val, num);
	min_val = min(min_val, num);	
    }

    vector<int> counter(max_val - min_val + 1, 0);
    for (int num : nums) {
	counter[num - min_val]++;
    }

    int ptr = 0;
    for (int i = 0; i < counter.size(); i++) {
	while (counter[i]--) {
	    nums[ptr++] = i + min_val;
	}
    }
}

void Sort::qsort(vector<int> &nums) {
    qsort(0, nums.size() - 1, nums);
}

void Sort::qsort(int left, int right, vector<int> &nums) {
    if (left >= right) return;
    int mid = partition(left, right, nums);
    qsort(left, mid - 1, nums);
    qsort(mid + 1, right, nums);
}

int Sort::partition(int left, int right, vector<int> &nums) {
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

int main() {
    Sort s;
    vector<int> v{1, 7, 2, 4, 3, 1, 4};
    s.sort(v, BUBBLE);
    s.print(v);

    return 0;
}
