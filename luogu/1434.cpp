#include <iostream>

using namespace std;

int m, n;
int board[101][101];
int memo[101][101];
int xy[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int dfs(int x, int y) {
    if (memo[x][y]) return memo[x][y];

    int rst = 0;
    for (int i = 0; i < 4; i++) {
	int xx = x + xy[i][0];
	int yy = y + xy[i][1];
	if (xx < 0 || yy < 0 || xx == m || yy == n || board[xx][yy] >= board[x][y]) continue;
	rst = max(rst, dfs(xx, yy));
    }

    return (memo[x][y] = rst + 1);
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
	    scanf("%d", &board[i][j]);
	}
    }

    int rst = 0;
    for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
	    rst = max(rst, dfs(i, j));
	}
    }

    cout << rst << endl;

    return 0;
}
