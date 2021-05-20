#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> matrix(n, vector<bool>(n));
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    bool val;
	    cin >> val;
	    matrix[i][j] = val;

	    if (i != j && matrix[i][j])
		cnt[j]++;
	}
    }

    for (int i = 0; i < n; i++) {
	if (cnt[i] >= n / 2)
	    cout << i + 1 << " ";
    }

    return 0;
}
