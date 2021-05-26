// LCA问题(只有两种颜色，可以用并查集做)
#include <iostream>
#include <numeric>

using namespace std;

const int N = 1e5 + 10;

char s[N];
int ps[N];

int find(int a) {
    return a == ps[a] ? a : ps[a] = find(ps[a]);
}

void merge(int a, int b) {
    int p1 = find(a), p2 = find(b);
    if (p1 != p2)
	ps[p2] = p1;
}

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    iota(ps + 1, ps + 1 + n, 1);
    for (int i = 0; i < n - 1; i++) {
	scanf("%d %d", &a, &b);
	if (s[a] == s[b])
	    merge(a, b);
    }

    char c;
    while (m--) {
	scanf("%d %d %c", &a, &b, &c);
	printf("%d", find(a) != find(b) || s[find(a)] == c);
    }
    printf("\n");

    return 0;
}
