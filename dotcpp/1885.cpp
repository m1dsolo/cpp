#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int n, k;

int get_k(int mid) {
    int k = 0;
    for (pair<int, int> &p : v) {
	k += (p.first / mid) * (p.second / mid);
    }
    return k;
}

int main() {
    cin >> n >> k;
    v.reserve(n);
    int tmpa, tmpb;
    int left = 1, right = 0;
    for (int i = 0; i < n; i++) {
	cin >> tmpa >> tmpb;
	v.push_back({tmpa, tmpb});
	right = max(right, min(tmpa, tmpb));
    }

    int rst = 0;
    // 需要求的人数大于等于k，所以相当于求k的右边界
    while (left <= right) {
	int mid = (left + right) / 2;
	if (get_k(mid) >= k)
	    left = mid + 1;
	else
	    right = mid - 1;
    }

    cout << right << endl;

    return 0;
}
