#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
using P = pair<int, int>;

P arr[1010];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int min_num = INT_MAX, max_num = INT_MIN, min_val = INT_MAX;
    for (int i = 0; i < n; i++) {
	scanf("%d %d", &arr[i].first, &arr[i].second);
	min_num = min(min_num, arr[i].first);
	max_num = max(max_num, arr[i].first);
	min_val = min(min_val, arr[i].second);
    }
    if (k == 1) {
	printf("%d\n", min_val);
    }
    else {
	int min_index, max_index, min_val = INT_MAX, max_val = INT_MAX;
	for (int i = 0; i < n; i++) {
	    if (arr[i].first == min_num && arr[i].second < min_val) {
		min_val = arr[i].second;
		min_index = i;
	    }
	    if (arr[i].first == max_num && arr[i].second < max_val) {
		max_val = arr[i].second;
		max_index = i;
	    }
	}
	arr[min_index].second = INT_MAX;
	arr[max_index].second = INT_MAX;

	int rst = min_val + max_val;
	sort(arr, arr + n, [](const P &p1, const P &p2) {
	    return p1.second < p2.second;
	});
	for (int i = 0; i < k - 2; i++)
	    rst += arr[i].second;
	printf("%d\n", rst);
    }

    return 0;
}
