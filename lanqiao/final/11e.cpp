#include <iostream>
#include <unordered_set>

using namespace std;

bool visited[4][4];

int xy[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int dfs(int x, int y, int num) {
    if (++num == 16) return 1;
    visited[x][y] = true;
    int rst = 0;
    for (int i = 0; i < 4; i++) {
	int xx = x + xy[i][0], yy = y + xy[i][1];
	if (xx >= 0 && yy >= 0 && xx < 4 && yy < 4 && !visited[xx][yy])
	    rst += dfs(xx, yy, num);
    }
    visited[x][y] = false;
    return rst;
}

int main() {
    int rst = 0;
    for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4; j++) {
	    rst += dfs(i, j, 0);
	}
    }

    cout << rst << endl;

    return 0;
}
