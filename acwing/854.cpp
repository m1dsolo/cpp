#include <iostream>
#include <cstring>

using namespace std;

const int N = 210, INT_MAX = 0x3f3f3f3f;

int dis[N][N];

int main() {
    int n, m, k, u, v, w;
    scanf("%d %d %d", &n, &m, &k);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++)
	dis[i][i] = 0;
    while (m--) {
	scanf("%d %d %d", &u, &v, &w);
	dis[u][v] = min(dis[u][v], w);	// 1.注意重边和覆盖dis[i][i]
    }

    for (int k = 1; k <= n; k++) {	// 2.注意循环顺序
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++)
		if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX)   // 3.注意负边
		    dis[i][j] = min(dis[i][j] ,dis[i][k] + dis[k][j]);
	}
    }

    while (k--) {
	scanf("%d %d", &u, &v);
	if (dis[u][v] == INT_MAX) puts("impossible");
	else printf("%d\n", dis[u][v]);
    }

    return 0;
}
