#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int n;
vector<vector<char>> board;

// true是能存活
bool dfs(int i, int j) {
    if (i < 1 || j < 1 || i >= n - 1 || j >= n - 1 || board[i][j] != '#')
	return false;
    board[i][j] = 'a';
    bool flag = false;
    if (dfs(i - 1, j)) flag = true;
    if (dfs(i + 1, j)) flag = true;
    if (dfs(i, j - 1)) flag = true;
    if (dfs(i, j + 1)) flag = true;
    if (flag || (board[i - 1][j] != '.' && board[i + 1][j] != '.' && board[i][j - 1] != '.' && board[i][j + 1] != '.'))
	return true;
    return false;
}

int main() {
    //ifstream ifs("data");
    cin >> n;
    //ifs >> n;
    board = vector<vector<char>>(n, vector<char>(n, false));
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    cin >> board[i][j];
	    //ifs >> board[i][j];
	}
    }

    int rst = 0;
    for (int i = 1; i < n - 1; i++) {
	for (int j = 1; j < n - 1; j++) {
	    if (board[i][j] == '#') {
		rst += !dfs(i, j);
	    }	
	}
    }
    cout << rst << endl;

    return 0;
}
