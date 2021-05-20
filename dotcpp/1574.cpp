#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

void dfs(int index) {
    if (index == n) {
	return;
    }
    int min_index = index;
    for (int i = index + 1; i < n; i++) {
	min_index = (v[i] < v[min_index]) ? i : min_index;
    }

    cout << "swap(a[" << index << "], a[" << min_index << "]):";
    swap(v[index], v[min_index]);
    for (int i = 0; i < n - 1; i++)
	cout << v[i] << " ";
    cout << v.back() << endl;

    dfs(index + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
	v.reserve(n);
	int val; cin >> val;
	v.push_back(val);
    }

    dfs(0);

    return 0;
}
