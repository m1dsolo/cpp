#include <iostream>

using namespace std;

int main() {
    string rst = "";
    string s;
    while (cin >> s) {
	if (s.length() > rst.length()) 
	    rst = s;
    }

    cout << rst << endl;

    return 0;
}

