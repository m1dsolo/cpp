#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
using P = pair<int, int>;

const int N = 210;

char arr[N][N];
int xy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d", &n, &m);
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++) {
	    scanf("%s", arr[i] + 1);
	    if (!x) {
		for (int j = 1; j <= m; j++) {
		    if (arr[i][j] == 'S') {
			x = i, y = j;
			break;
		    }
		}
	    }
	}
	queue<P> q;
	q.push({x, y});
	unordered_set<int> set;
	set.insert(x * 1000 + y);
	int l = 0;
	bool finish = false;
	while (int size = q.size()) {
	    while (size--) {
		int x = q.front().first, y = q.front().second; q.pop();
		if (arr[x][y] == 'E') {
		    finish = true;
		    break;
		}
		for (int i = 0; i < 4; i++) {
		    int xx = x + xy[i][0], yy = y + xy[i][1];
		    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && arr[xx][yy] != '#' && !set.count(xx * 1000 + yy)) {
			set.insert(xx * 1000 + yy);
			q.push({xx, yy});
		    }
		}
	    }
	    if (finish) break;
	    l++;
	}
	if (!finish)
	    printf("oop!\n");
	else
	    printf("%d\n", l);
    }

    return 0;
}
