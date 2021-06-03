#include <iostream>

using namespace std;

int n, path[20], sz;

void dfs(int num) {
    if (num == n + 1) {
	for (int i = 0; i < sz; i++)
	    printf("%d ", path[i]);
	printf("\n");
    } else {
	dfs(num + 1);
	path[sz++] = num;
	dfs(num + 1);
	sz--;
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);

    return 0;
}
