#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<vector<char>> board(9, vector<char>(9));
vector<bitset<9>> rows(9, bitset<9>());
vector<bitset<9>> cols(9, bitset<9>());
vector<bitset<9>> cells(9, bitset<9>());

bitset<9> get_bitset(int i, int j) {
    return ~(rows[i] | cols[j] | cells[i / 3 * 3 + j / 3]);
}

pair<int, int> get_next() {
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

void fill_bitset(int i, int j, int n, int flag) {
    rows[i][n] = flag;
    cols[j][n] = flag;
    cells[i / 3 * 3 + j / 3][n] = flag;
}

bool dfs(int cnt) {
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

int main() {
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9; j++) {
	    cin >> board[i][j];
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

    cout << (dfs(cnt) ? "success" : "fail") << endl;

    for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9; j++) {
	    cout << board[i][j] << " ";
	}
	cout << endl;
    }
}
