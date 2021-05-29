#include <iostream>

using namespace std;


int main() {
    //ios::sync_with_stdio(false);
    int t;
    cin >> t;
    string s, tmp;
    int a = 0, b = 0, c = 0;
    getline(cin, s);
    while (getline(cin, s)) {
	if (s == "=====") {
	    cout << a << " " << b << " " << c << endl;
	    a = 0, b = 0, c = 0;
	    continue;
	}
	a++;
	char pre = ' ';
	for (char c : s) {
	    if (c == ' ' && pre != ' ')
		b++;
	    pre = c;
	}
	if (pre != ' ') b++;
	c += s.length();
    }
    cout << a << " " << b << " " << c << endl;

    return 0;
}
