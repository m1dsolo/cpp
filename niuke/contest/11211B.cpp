#include <iostream>

using namespace std;

const int N = 20;

int n, arr[N][N], rst = 2e9, MAX;
bool visited[N];

void dfs(int index, int min_val, int max_val, int sum, int size) {
    visited[index] = true;
    if (sum - MAX < rst) {
	if (++size == n)
	    rst = min(rst, sum - max_val + min_val);
	else {
	    for (int i = 0; i < n; i++) {
		if (!visited[i]) {
		    int len = arr[index][i];
		    dfs(i, min(min_val, len), max(max_val, len), sum + len, size);
		}
	    }
	}
    }
    visited[index] = false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    scanf("%d", &arr[i][j]);
	    MAX = max(MAX, arr[i][j]);
	}
    }

    for (int i = 0; i < n; i++)
	dfs(i, 1e6, 0, 0, 0);

    printf("%d\n", rst);

    return 0;
}
