#include <iostream>
#include <vector>

using namespace std;


int i_min = 0, j_min = 0, i_max, j_max;

int main() {
    int row, col;
    cin >> row >> col;
    i_max = row;
    j_max = col;
    vector<vector<int>> board(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
	for (int j = 0; j < col; j++) {
	    int val;
	    cin >> val;
	    board[i][j] = val;
	}
    }

    int direction = 0;
    while (i_min < i_max && j_min < j_max) {
	if (i_min == i_max - 1 && j_min == j_max - 1) {
	    cout << board[i_min][j_min] << endl;
	    break;
	}
	switch (direction) {
	    case 0:
		for (int i = i_min; i < i_max; i++)
		    cout << board[i][j_min] << " ";
		j_min++;
		break;
	    case 1:
		for (int j = j_min; j < j_max; j++)
		    cout << board[i_max - 1][j] << " ";
		i_max--;
		break;
	    case 2:
		for (int i = i_max - 1; i >= i_min; i--)
		    cout << board[i][j_max - 1] << " ";
		j_max--;
		break;
	    case 3:
		for (int j = j_max - 1; j >= j_min; j--)
		    cout << board[i_min][j] << " ";
		i_min++;
		break;
	}
	direction = (direction + 1) % 4;
    }


    return 0;
} 

