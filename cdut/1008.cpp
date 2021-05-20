// https://www.cnblogs.com/liutianrui/p/7652876.html
// bzoj 1028
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 410;

int n;
int map[N], tmp[N], rst[N], size;

// 很巧妙
bool is_ok() {
    memcpy(tmp + 1, map + 1, sizeof(int) * (n + 2));
    for (int i = 1; i <= n; i++) {
	if (tmp[i] < 0) return false;
	tmp[i + 1] -= tmp[i] % 3;
	tmp[i + 2] -= tmp[i] % 3;
    }
    return tmp[n + 1] >= 0 && tmp[n + 2] >= 0;
}

int main() {
    int m, a;
    scanf("%d %d", &n, &m);
    while (scanf("%d", &a) != EOF)
	map[a]++;

    for (int i = 1; i <= n; i++) {
	map[i]++;
	for (int j = 1; j <= n; j++) {
	    if (map[j] >= 2) {
		map[j] -= 2;
		bool ok = is_ok();
		map[j] += 2;
		if (ok) {
		    rst[size++] = i;
		    break;
		}
	    }
	}
	map[i]--;
    }

    if (!size)
	printf("NO\n");
    else {
	sort(rst, rst + size);
	for (int i = 0; i < size - 1; i++)
	    printf("%d ", rst[i]);
	printf("%d\n", rst[size - 1]);
    }

    return 0;
}
