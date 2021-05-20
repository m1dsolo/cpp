#include <iostream>

using namespace std;

int main() {
    int arr[26] = {0};
    string s;
    cin >> s;
    int max_num = 1;
    char rst = s[0];
    for (char c : s) {
	if (++arr[c - 'a'] > max_num) {
	    max_num = arr[c - 'a'];
	    rst = c;
	}
    }
    cout << rst << endl << max_num << endl;

    return 0;
}
