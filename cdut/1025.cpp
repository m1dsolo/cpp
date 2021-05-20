#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int rst = 0;
    int num = 0;
    for (char c : s) {
	if (c == 'B')
	    num++;
	else if (num > 0) {
	    rst++;
	    num--;
	}
    }

    cout << rst << endl;

    return 0;
}
