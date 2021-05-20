// cant ac, i dont know why
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> board(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
	for (int j = 0; j < col; j++) {
	    int val;
	    cin >> val;
	    board[i][j] = val;
	}
    }

    int rst = INT_MIN;
    for (int i = 0; i < row; i++) {
	vector<int> v(col, 0);
	for (int j = i; j < row; j++) {
	    for (int k = 0; k < col; k++) {
		v[k] += board[j][k];
	    }
	}

	int dp = v[0];
	for (int k = 1; k < col; k++) {
	    dp = max(dp + v[k], v[k]);
	    rst = max(rst, dp);
	}
    }

    cout << rst << endl;

    return 0;
}
