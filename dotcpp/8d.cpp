#include <iostream>

using namespace std;

int rst = 0;
bool used[7][7] = {false};
int xs[4] = {0, 0, -1, 1};
int ys[4] = {-1, 1, 0, 0};

void dfs(int x, int y) {
    if (!x || !y || x == 6 || y == 6) {
	rst++;
	return;
    }
    used[x][y] = true;
    used[6 - x][6 - y] = true;
    for (int i = 0; i < 4; i++) {
	int xx = x + xs[i];
	int yy = y + ys[i];
	if (xx < 0 || yy < 0 || xx > 6 || yy > 6 || used[xx][yy])
	    continue;
	dfs(xx, yy);
    }
    used[x][y] = false;
    used[6 - x][6 - y] = false;
}

int main() {
    dfs(3, 3);

    cout << rst / 4 << endl;

    return 0;
}
