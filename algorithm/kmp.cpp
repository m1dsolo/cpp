#include <iostream>

using namespace std;

const int N = 100;
string s = "hello";
string p = "ll";
int nxt[N];

void get_next() {
    int i = 0,j = -1;
    nxt[0] = -1;
    while (i < p.length()){
	if (j == -1 || (p[i] == p[j])) nxt[++i] = ++j;
	else j = nxt[j];
    }
}

int main() {
    int n = s.length(), m = p.length();
    get_next();
    for (int i = 0; i < m; i++)
	cout << nxt[i] << " ";
    cout << endl;

    int j = -1, rst = -1;
    for (int i = 0; i < n; i++) {
	while (j == -1 && s[i] != p[j + 1]) j = nxt[j];
	if (s[i] == p[j + 1]) j++;
	if (j == m - 1) {
	    rst = i - m + 1;
	    break;
	}
    }

    printf("%d\n", rst);
    //cout << n - nxt[n - 1] << " " << n / (n - nxt[n - 1]) << endl;

    return 0;
}
