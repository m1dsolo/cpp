#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> board;
int rst = 0;

bool is_ok(int i, int j) {
    if (board[i][j] == board[i - 1][j] && board[i][j] == board[i][j - 1] && board[i][j] == board[i - 1][j - 1])
	return false;
    if (board[i][j] == board[i - 1][j] && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i][j + 1])
	return false;
    if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i][j - 1])
	return false;
    if (board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1])
	return false;
    return true;
}

void dfs(int i, int j) {
    if (i == m && j == n) {
	rst++;
	return;
    }
    if (j > n) {
	dfs(i + 1, 1);
	return;
    }
    if (board[i][j] == -1) {
	if (i < m && board[i + 1][j] == -1) {
	    for (int k = 0; k < 2; k++) {
		board[i][j] = k;
		board[i + 1][j] = k;
		if (is_ok(i, j))
		    dfs(i, j + 1);
		board[i][j] = -1;
		board[i + 1][j] = -1;
	    }
	}
	if (j < n && board[i][j + 1] == -1) {
	    for (int k = 0; k < 2; k++) {
		board[i][j] = k;
		board[i][j + 1] = k;
		if (is_ok(i, j))
		    dfs(i, j + 1);
		board[i][j] = -1;
		board[i][j + 1] = -1;
	    }
	}
    }
    else
	dfs(i, j + 1);
}
int main() {
    m = 3, n = 10;
    board = vector<vector<int>>(m + 2, vector<int>(n + 2, -1));
    dfs(1, 1);

    cout << rst << endl;

    return 0;
}
