// O(n) = pow(3, n)
// maybe should use dp, but i dont know

#include <iostream>
#include <vector>

using namespace std;

vector<int> weights;
bool rst;
void dfs(int index, int val) {
    if (index == weights.size()) {
	if (!val) rst = true;
	return;
    }

    dfs(index + 1, val - weights[index]);
    dfs(index + 1, val);
    dfs(index + 1, val + weights[index]);
}

int main() {
    int n, m;
    cin >> n >> m;
    weights.reserve(n); 
    int val;
    for (int i = 0; i < n; i++) {
	cin >> val;
	weights.push_back(val);
    }
    for (int i = 0; i < m; i++) {
	cin >> val;
	rst = false;
	dfs(0, val);
	cout << ((rst) ? "YES" : "NO") << endl;
    }

    return 0;
}
