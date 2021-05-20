#include <iostream>
#include <sstream>

using namespace std;

const int N = 5e6 + 10;
int n;
string tree[N];
string rst;

void dfs(int i) {
    if (i > n) return;

    dfs(2 * i + 1);
    rst += tree[i] + ',';
    dfs(2 * i);
}

int main() {
    scanf("%d", &n);
    string s, tmp;
    cin >> s;
    stringstream ss(s);

    for (int i = 1; i <= n; i++) {
	while (getline(ss, tmp, ',')) {
	    tree[i] += tmp;
	    if (tmp.back() != '~')
		break;
	    tree[i] += ',';
	}
    }

    dfs(1);

    cout << rst.substr(0, rst.length() - 1) << endl;

    return 0;
}
