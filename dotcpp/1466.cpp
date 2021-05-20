#include <iostream>

using namespace std;

int main() {
    string s0, s1;
    cin >> s0 >> s1;
    if (s0.length() != s1.length()) {
	cout << 1 << endl;
	return 0;
    }

    for (int i = 0; i < s0.length(); i++) {
	if (s0[i] != s1[i]) {
	    if (toupper(s0[i]) != toupper(s1[i])) {
		cout << 4 << endl;
		return 0;
	    }
	    else {
		cout << 3 << endl;
		return 0;
	    }
	}
    }

    cout << 2 << endl;

    return 0;
}

