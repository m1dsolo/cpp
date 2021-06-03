#include <iostream>

using namespace std;

int n, path[20], sz;
bool visited[20];

void dfs() {
    if (sz == n) {
	for (int i = 1; i <= sz; i++)
	    printf("%d ", path[i]);
	printf("\n");
    } else {
	for (int i = 1; i <= n; i++) {
	    if (!visited[i]) {
		visited[i] = true;
		path[++sz] = i;
		dfs();
		sz--;
		visited[i] = false;
	    }
	}
    }
}

int main() {
    scanf("%d", &n);

    dfs();

    return 0;
}
