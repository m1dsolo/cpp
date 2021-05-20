#include <iostream>
#include <vector>

using namespace std;

// 前缀和超时
//int main() {
    //int n, k;
    //cin >> n >> k;
    //vector<int> nums(n), presum(n);
    //for (int i = 0; i < n; i++) {
	//cin >> nums[i];
    //}
    //presum[0] = nums[0];
    //int rst = !(presum[0] % k);
    //for (int i = 1; i < n; i++) {
	//presum[i] = presum[i - 1] + nums[i];
	//if (!(presum[i] % k)) rst++;
    //}

    //for (int i = 0; i < n - 1; i++) {
	//for (int j = i + 1; j < n; j++) {
	    //if (!((presum[j] - presum[i]) % k)) rst++;
	//}
    //}
    //cout << rst << endl;

    //return 0;
//}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> map(n);
    long long rst = 0;
    long long sum = 0;
    int num;
    for (int i = 0; i < n; i++) {
	cin >> num;
	sum = (sum + num) % k;
	rst += map[sum]++;
    }

    cout << rst + map[0] << endl;

    return 0;
}
