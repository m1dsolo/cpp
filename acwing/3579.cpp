#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;

int arr[N], path[N], sz, rst[N];
bool visited[N];

int dfs(int a) {
    if (visited[a]) return 0;
    visited[a] = true;
    path[sz++] = a;
    return dfs(arr[a]) + 1;
}

int main() {
    int t, n, a;
    scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	    scanf("%d", &arr[i]);
	memset(visited + 1, false, n);
	for (int i = 1; i <= n; i++) {
	    if (a = dfs(i)) {
		for (int i = 0; i < sz; i++)
		    rst[path[i]] = a;
		sz = 0;
	    }
	}
	for (int i = 1; i <= n; i++)
	    printf("%d ", rst[i]);
	printf("\n");
    }

    return 0;
}
