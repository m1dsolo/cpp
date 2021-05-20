#include <iostream>

using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    char c;
    bool board[row][col] = {false};
    for (int i = row - 1; i >= 0; i--) {
	for (int j = 0; j < col; j++) {
	    cin >> c;
	    if (c == '.') board[i][j] = true;
	}
    }


    return 0;
}
