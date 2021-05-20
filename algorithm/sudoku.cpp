#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <fstream>

using namespace std;

class Sudoku {
private:
    vector<vector<char>> board;
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<bitset<9>> cells;	// two dimension to one dimension
    bitset<9> get_bitset(int i, int j);
    pair<int, int> get_next();
    void fill_bitset(int i, int j, int n, bool flag);
    bool dfs(int cnt);
public:
    Sudoku() {
	board = vector<vector<char>>(9, vector<char>(9));
    }
    Sudoku(const vector<vector<char>> &_board) : board(_board) {}
    void read(const string &file);
    void solve();
    void print();
};

// get bitset that represent the nums that (x, y) position can fill in
bitset<9> Sudoku::get_bitset(int i, int j) {
    return ~(rows[i] | cols[j] | cells[i / 3 * 3 + j / 3]);
}

pair<int, int> Sudoku::get_next() {
    int min_cnt = 10;
    pair<int, int> rst;
    for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9; j++) {
	    if (board[i][j] != '.') continue;
	    bitset<9> set = get_bitset(i, j);
	    int cnt = set.count();
	    if (cnt < min_cnt) {
		min_cnt = cnt;
		rst = {i, j};
	    }
	} 
    }

    return rst;
}

void Sudoku::fill_bitset(int i, int j, int n, bool flag) {
    rows[i][n] = flag;
    cols[j][n] = flag;
    cells[i / 3 * 3 + j / 3][n] = flag;
}

bool Sudoku::dfs(int cnt) {
    if (!cnt) return true;

    pair<int, int> p = get_next();
    int i = p.first, j = p.second;
    bitset<9> set = get_bitset(i, j);

    for (int n = 0; n < 9; n++) {
	if (!set[n]) continue;
	board[i][j] = n + '1';
	fill_bitset(i, j, n, true);
	if (dfs(cnt - 1)) return true;
	fill_bitset(i, j, n, false);
	board[i][j] = '.';
    }

    return false;
}

void Sudoku::read(const string &file) {
    ifstream fp(file);
    for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9; j++) {
	    fp >> board[i][j];
	}
    }
}

void Sudoku::solve() {
    rows = vector<bitset<9>>(9, bitset<9>(0));
    cols = vector<bitset<9>>(9, bitset<9>(0));
    cells = vector<bitset<9>>(9, bitset<9>(0));

    int cnt = 0;
    for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9; j++) {
	    if (board[i][j] == '.') {
		cnt++;
		continue;
	    }	
	    int n = board[i][j] - '1';
	    rows[i][n] = 1;
	    cols[j][n] = 1;
	    cells[i / 3 * 3 + j / 3][n] = 1;
	}
    }

    cout << ((dfs(cnt) ? "success" : "fail")) << endl;
}

void Sudoku::print() {
    for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9; j++)
	    cout << board[i][j] << " ";
	cout << endl;
    }
}

int main() {
    Sudoku sudoku;
    sudoku.read("sudoku.dat");
    sudoku.solve();
    sudoku.print();

    return 0;
}
