#include <iostream>
#include <climits>

using namespace std;

long long get_abs_sum(int *arr, int n) {
    long long rst = 0;
    for (int i = 0; i < n; i++)
	rst += abs(arr[i]);
    
    return rst;
}

long long get_sum(int *arr, int n) {
    long long rst = 0;
    for (int i = 0; i < n; i++)
	rst += arr[i];

    return rst;
}

int main() {
    int n, m;
    cin >> n >> m;
    int size = n + m + 1;
    int arr[size];
    int negative = 0;
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    for (int i = 0; i < size; i++) {
	cin >> arr[i]; 
	max_val = max(max_val, arr[i]);
	min_val = min(min_val, arr[i]);
	if (arr[i] < 0)
	    negative++;
    }
    
    long long rst;
    if (negative == m) {
	rst = get_abs_sum(arr, size);
    }
    else if (negative > m) {
	if (negative == size)
	    rst = get_abs_sum(arr, size) + 2 * max_val;
	else if (!m)
	    rst = get_sum(arr, size);
	else
	    rst = get_abs_sum(arr, size);
    }
    else if (negative < m) {
	if (!negative)
	    rst = get_abs_sum(arr, size) - 2 * min_val;
	else
	    rst = get_abs_sum(arr,size);
    }
    
    cout << rst << endl;

    return 0;
}
