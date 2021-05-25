#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
bool adj[N][N];
int n, num, arr[N], rst[N], rst_num;

void dfs(int index) {
    if (n - index < rst_num - num) return;
    if (index > n) {
	if (num > rst_num) {
	    rst_num = num;
	    memcpy(rst, arr, sizeof(rst));
	}
    }
    else {
	bool flag = true;
	for (int i = 1; i < index; i++) {
	    if (arr[i] && adj[i][index]) {
		flag = false;
		break;
	    }
	}
	if (flag) {
	    num++;
	    arr[index] = 1;
	    dfs(index + 1);
	    arr[index] = 0;
	    num--;
	}
	dfs(index + 1);
    }
}

int main() {
    int m, u, v;
    scanf("%d %d", &n, &m);
    while (m--) {
	scanf("%d %d", &u, &v);
	adj[u][v] = true;
	adj[v][u] = true;
    }

    dfs(1);

    printf("%d\n", rst_num);
    for (int i = 1; i <= n; i++)
	printf("%d ", rst[i]);
    printf("\n");

    return 0;
}
