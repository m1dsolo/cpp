#include <iostream>

using namespace std;

int main() {
    int n, a = 0, b = 0;
    char target;
    string s;
    cin >> n >> target >> s;
    for (char c : s) {
	if (c == 'A')
	    a++;
	else
	    b++;
    }
    b += a - (a % 2);
    if (target == 'B')
	cout << b << endl;
    else if (a % 2)
	cout << b + 1 << endl;
    else
	cout << b - 1 << endl;

    return 0;
}
