#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int dfs(int left, int right, int mid) {
    if (left > right) return 1;

}

int main() {
    int n;
    cin >> n;
    v = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
	cin >> v[i];
    }

    int rst = 0;
    for (int i = 1; i <= n; i++) {
	rst = max(rst, dfs(1, n, i));
    }

    return 0;
}
