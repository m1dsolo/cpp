#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int len;
    string s;
    while (t--) {
	cin >> len >> s;
	string rst;
	for (int i = 0; i < len; i += 5) {
	    int num = stoi(s.substr(i, 5));
	    cout << num << endl;
	    string tmp;
	    for (int j = 0; j < 3; j++) {
		tmp = char('a' + num % 26) + tmp;
		num /= 26;
	    }
	    rst += tmp;
	}
	cout << rst << endl;
    }

    return 0;
}
