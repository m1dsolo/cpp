#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int rst = INT_MAX;
int row, col;
vector<vector<int>> board;
vector<vector<bool>> used;
void dfs(int x, int y, int val, int num) {
    if (x < 0 || y < 0 || x == row || y == col) return;
    if (used[x][y]) return;
    if (val < 0) return;
    if (!val) {
	rst = min(rst, num);
	return;
    }
    
    used[x][y] = true;
    num++;
    val -= board[x][y];

    dfs(x + 1, y, val, num); 
    dfs(x - 1, y, val, num);
    dfs(x, y + 1, val, num); 
    dfs(x, y - 1, val, num);

    val += board[x][y];
    num--;
    used[x][y] = false;
}

int main() {
    cin >> col >> row;
    board = vector<vector<int>> (row, vector<int>(col));
    used = vector<vector<bool>> (row, vector<bool>(col));
    int sum = 0;
    for (int i = 0; i < row; i++) {
	for (int j = 0; j < col; j++) {
	    int val;
	    cin >> val;
	    board[i][j] = val;
	    sum += board[i][j];
	}
    }

    dfs(0, 0, sum / 2, 0);

    cout << ((rst == INT_MAX) ? 0 : rst) << endl;

    return 0;
}
