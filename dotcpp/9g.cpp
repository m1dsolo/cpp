#include <iostream>
#include <fstream>

using namespace std;

char board[1000][1000];
int n;
int is[4] = {0, 0, -1, 1};
int js[4] = {-1, 1, 0, 0};

bool dfs(int ii, int jj) {
    bool rst = true;	    // 整体不会被淹
    bool flag = false;	    // 当前块不会被淹
    board[ii][jj] = 'a';
    for (int k = 0; k < 4; k++) {
	int i = ii + is[k];
	int j = jj + js[k];
	if (i < 0 || j < 0 || i >= n || j >= n)
	    continue;
	if (board[i][j] == '.')	    // 当前块大陆，如果有一块海，就会被淹
	    flag = true;
	if (board[i][j] != '#')
	    continue;
	if (!dfs(i, j))	    // 里面只要一块大陆不被淹，整体就不会被淹
	    rst = false;
    }
    if (!flag) rst = false;	// 当前块大陆不被淹，整体也不会被淹

    return rst;
}

int main() {
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    scanf("%c", &board[i][j]);
	}
	getchar();
    }

    int rst = 0;
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    if (board[i][j] == '#' && dfs(i, j)) rst++;
	}
    }

    cout << rst << endl;

    return 0;
}
