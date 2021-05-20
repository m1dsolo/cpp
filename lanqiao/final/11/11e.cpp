#include <iostream>
#include <vector>

using namespace std;

int n = 5;
vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));

int rst = 0;
int xy[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
// 结果208要去掉2((0, 0)->(0, 1)->(0, 0)和(0, 0)->(1, 0)->(0, 0))
void dfs(int x, int y, int level) {
    if (level > 12) return;
    if (!x && !y && level) {
	rst++;
	return;
    }
    visited[x][y] = true;
    visited[0][0] = false;
    for (int i = 0; i < 4; i++) {
	int xx = x + xy[i][0];
	int yy = y + xy[i][1];
	if (xx < 0 || yy < 0 || xx > n || yy > n || visited[xx][yy]) continue;
	dfs(xx, yy, level + 1);
    }
    visited[x][y] = false;
}
int main() {
    dfs(0, 0, 0);

    cout << rst << endl;

    return 0;
}
