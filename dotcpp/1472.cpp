#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, order;
    cin >> n >> order;
    if (!order) {
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n - 1; j++) {
		cout << ((i == j) ? 1 : 0) << " ";
	    }
	    cout << ((i == n - 1) ? 1 : 0) << endl;
	}

	return 0;
    }

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    int val;
	    cin >> val;
	    matrix[i][j] = val;
	}
    }
    vector<vector<int>> rst = matrix;

    for (int i = 1; i < order; i++) {
	vector<vector<int>> tmp(n, vector<int>(n, 0));
	for (int j = 0; j < n; j++) {
	    for (int k = 0; k < n; k++) {
		for (int l = 0; l < n; l++) {
		    tmp[j][k] += rst[j][l] * matrix[l][k];
		}
	    }
	}
	rst = tmp;
    }

    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n - 1; j++) {
	    cout << rst[i][j] << " ";
	}
	cout << rst[i][n - 1] << endl;
    }

    return 0;
}
