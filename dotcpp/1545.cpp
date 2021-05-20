#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int i = 1;
    while (i <= s.length() / 2) {
	if (s.length() % i) {
	    i++;
	    continue;
	}
	string tmp = s.substr(0, i);
	int j = i;
	for (; j < s.length(); j += i) {
	    if (s.substr(j, i) != tmp)
		break;
	}
	if (j == s.length()) {
	    cout << s.length() / i << endl;
	    return 0;
	}
	i++;
    }

    cout << 1 << endl;
    return 0;
}
