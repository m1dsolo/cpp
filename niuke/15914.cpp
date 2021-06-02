#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, tree[10][N];
char s[N];

void update(int i, int d, int num) {
    for (; i <= n; i += i & -i)
	tree[num][i] += d;
}

int query(int i, int num) {
    int rst = 0;
    for (; i; i -= i & -i)
	rst += tree[num][i];
    return rst;
}

int query(int l, int r, int num) {
    if (l > n || r < 1) return 0;
    return query(min(r, n), num) - query(max(0, l - 1), num);
}

int main() {
    while (scanf("%c", &s[++n]) != EOF) {
	if (!isdigit(s[n])) {
	    n--;
	    break;
	}
    }
    int q, l, r, i, x;
    scanf("%d %d %d", &q, &l, &r);

    int rst = 0;
    for (int i = 1; i <= n; i++) {
	update(i, 1, s[i] - '0');
	for (int j = s[i] - '0' + 1; j <= 9; j++)
	    rst += query(i - r + 1, i - l + 1, j);
    }

    while (q--) {
	scanf("%d %d", &i, &x);
	update(i, -1, s[i] - '0');
	// i左面大于s[i]的减，大于x的加，右面小于s[i]的减，小于x的加
	for (int j = s[i] - '0' + 1; j <= 9; j++)
	    rst -= query(i - r + 1, i - l + 1, j);
	for (int j = x + 1; j <= 9; j++)
	    rst += query(i - r + 1, i - l + 1, j);
	for (int j = 0; j < s[i] - '0'; j++)
	    rst -= query(i + l - 1, i + r - 1, j);
	for (int j = 0; j < x; j++)
	    rst += query(i + l - 1, i + r - 1, j);
	printf("%d\n", rst);
	update(i, 1, x);
	s[i] = x + '0';
    }

    return 0;
}
