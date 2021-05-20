#include <iostream>
#include <vector>

using namespace std;

int rst = 0;
vector<int> weights;

void dfs(int index, int n, int m, int val, bool ok) {
    if (index >= n) {
	if (!m) rst = max(rst, val);
	return;
    }
    
    index++;
    if (ok)
	dfs(index, n, m - 1, val + weights[index - 1], false);	// plant
    dfs(index, n, m, val, true);				// not plant
}

int main() {
    int n, m;
    cin >> n >> m;
    if (m > n / 2) {
	cout << "Error!" << endl;
	return 0;
    }
    weights.reserve(n);
    for (int i = 0; i < n; i++) {
	int val;
	cin >> val;
	weights.push_back(val);
    }

    dfs(0, n - 1, m, 0, true);
    dfs(1, n, m, 0, true);
    cout << rst << endl;

    return 0;
}
