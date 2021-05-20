#include <iostream>

using namespace std;

void recursion(string &s, int index) {
    if (index >= s.length() / 2) {
	cout << endl << s << endl;
	return;
    }

    swap(s[index], s[s.length() - index - 1]);
    cout << s << endl;
    recursion(s, index + 1);
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    recursion(s, 0);

    return 0;
}
