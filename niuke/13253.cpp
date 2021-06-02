#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

string s, p;

int nxt[N];

int get_base() {
    int rst = 0;
    for (char c : p)
	rst = max(rst, isdigit(c) ? c - '0' : c - 'a' + 10);
    return rst;
}

string get_s(int n, int k) {
    string s;
    int a, b;
    for (int i = 1; i <= n; i++) {
	string tmp;
	a = i;
	while (a) {
	    b = a % k;
	    tmp += b < 10 ? b + '0' : b - 10 + 'A';
	    a /= k;
	}
	reverse(tmp.begin(), tmp.end());
	s += tmp;
    }
    return s;
}

void get_next() {
    int i = 0, j = -1;
    nxt[0] = -1;
    while (i < p.length()) {
	if (j == -1 || p[i] == p[j]) nxt[++i] = ++j;
	else j = nxt[j];
    }
}

bool kmp() {
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
	while (j == -1 && s[i] != p[j + 1]) j = nxt[j];
	if (s[i] == s[j + 1]) {
	    if (++j == p.length())
		return true;
	}
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n >> p;
    get_next();
    int k = get_base();
    for (; k <= 16; k++) {
	s = get_s(n, k);
	if (kmp()) {
	    printf("yes\n");
	    break;
	}
    }
    if (k == 17)
	printf("no\n");

    return 0;
}
