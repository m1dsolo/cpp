#include <iostream>

using namespace std;

const int N = 60;
char arr[N][N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
	scanf("%s", &arr[i][1]);

    int rst = 0;
    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= m; j++) {
	    if (arr[i][j] == '#') {
		if (arr[i][j - 1] == '.') rst++;
		if (arr[i][j + 1] == '.') rst++;
		if (arr[i - 1][j] == '.') rst++;
		if (arr[i + 1][j] == '.') rst++;
		if (i & 1) {
		    if (arr[i - 1][j - 1] == '.') rst++;
		    if (arr[i + 1][j - 1] == '.') rst++;
		}
		else {
		    if (arr[i - 1][j + 1] == '.') rst++;
		    if (arr[i + 1][j + 1] == '.') rst++;
		}
	    }
	}
    }

    printf("%d\n", rst);

    return 0;
}
