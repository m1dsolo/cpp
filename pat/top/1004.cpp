#include <iostream>

using namespace std;

const int N = 110;

int map[128], maps[N][128];

int n, m, cnt, valid, rst;
void dfs(int index) {
    if (valid == n)
	rst = min(rst, cnt - n);
    else {

    }
}

int main() {
    char c;
    while (scanf("%c", &c) != EOF) {
	if (c == '\n') break;
	map[c]++;
	n++;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
	while (scanf("%c", &c) != EOF) {
	    if (c == '\n') break;
	    maps[i][c]++;
	}
    }

    return 0;
}
