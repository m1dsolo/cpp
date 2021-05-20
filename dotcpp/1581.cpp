#include <iostream>
#include <climits>

using namespace std;

int rst = INT_MAX;
string s;

void dfs(int index) {
    if (index == s.length()) {
	return;
    }
    if (s.find("2012") != string::npos) {
	rst = min(rst, index);
    }

    for (int i = index; i < s.length(); i++) {
	swap(s[index], s[i]);
	dfs(index + 1);
	swap(s[index], s[i]);
    }
}

int main() {
    int len;
    cin >> len;
    cin >> s;

    dfs(0);

    cout << rst << endl;

    return 0;
}
