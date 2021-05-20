// 10进制转13进制
#include <iostream>

using namespace std;

string s = "0123456789ABC";

int main() {
    int a;
    cout << '#';
    for (int i = 0; i < 3; i++) {
	cin >> a;
	cout << s[a / 13] << s[a % 13];
    }
    cout << endl;

    return 0;
}
