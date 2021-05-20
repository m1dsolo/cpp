#include <iostream>
#include <sstream>

using namespace std;

bool is_palindrome(const string &s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
	if (s[left++] != s[right--])
	    return false;
    }
    return true;
}

bool is_ab(const string &s) {
    if (s[2] != s[0] || s[5] != s[0] || s[7] != s[0])
	return false;
    if (s[3] != s[1] || s[4] != s[1] || s[6] != s[1])
	return false;
    return true;
}

string get_palindrome(const string &s) {
    stringstream ss;
    ss << s[0] << s[1] << s[2] << s[3] << s[3] << s[2] << s[1] << s[0];
    return ss.str();
}

string get_ab(const string &s) {
    stringstream ss;
    ss << s[0] << s[1] << s[0] << s[1] << s[1] << s[0] << s[1] << s[0];
    return ss.str();
}

string operator+(const string &s, int n) {
    return to_string(stoi(s) + n);
}
int main() {
    string s;
    cin >> s;
    if (is_palindrome(s)) 
	cout << get_palindrome(s.substr(0, 4) + 1 + s.substr(4, 4)) << endl;
    else
	cout << get_palindrome(s) << endl;
    if (is_ab(s))
	cout << get_ab(s.substr(0, 2) + 1 + s.substr(2, 6)) << endl;
    else
	cout << get_ab(s) << endl;

    return 0;
}
