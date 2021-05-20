#include <iostream>
#include <vector>

using namespace std;

int x, y, direction;

void forward() {
    switch (direction) {
	case 0: x--; break;
	case 1: y++; break;
	case 2: x++; break;
	case 3: y--; break;
    }
}

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<bool>> board(row, vector<bool>(col));
    for (int i = 0; i < row; i++) {
	for (int j = 0; j < col; j++) {
	    bool val;
	    cin >> val;
	    board[i][j] = val;
	}
    }
    int k;
    char s;
    cin >> x >> y >> s >> k;

    switch (s) {
	case 'U': direction = 0; break;
	case 'R': direction = 1; break;
	case 'D': direction = 2; break;
	case 'L': direction = 3; break;
    }

    for (int i = 0; i < k; i++) {
	direction = (board[x][y]) ? ((direction + 1) % 4) : ((direction + 3) % 4);
	board[x][y] = !board[x][y];
	forward();
    }

    cout << x << " " << y << endl;

    return 0;
}
