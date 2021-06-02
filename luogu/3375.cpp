// https://as-the-moon.blog.luogu.org/solution-p3375
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

string s, p;
int nxt[N], n, m;

void get_next() {
    int i = 0, j = -1;
    nxt[0] = -1;
    while (i < m) {
	if (j == -1 || p[i] == p[j])
	    nxt[++i] = ++j;
	else
	    j = nxt[j];
    }
}

void kmp() {
    int i = 0, j = 0;
    while (i < n) {
	if (j == -1 || s[i] == p[j]) i++, j++;
	else j = nxt[j];
	if (j == m) {
	    printf("%d\n", i - m + 1), j = nxt[j];
	}
    }
    for (int i = 1; i <= m; i++)
	printf("%d ", nxt[i]);
    printf("\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin >> s >> p;
    n = s.length(), m = p.length();

    get_next();
    kmp();

    return 0;
}
