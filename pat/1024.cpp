#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string my_reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

bool is_palindrome(const string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
	if (s[i] != s[n - 1 - i])
	    return false;
    }
    return true;
}

string add(const string &s1, const string &s2) {
    string rst;
    int m = s1.length() - 1, n = s2.length() - 1, carry = 0;
    while (m >= 0 || n >= 0 || carry) {
	int val = (m >= 0 ? s1[m--] - '0' : 0) + (n >= 0 ? s2[n--] - '0' : 0) + carry;
	rst.push_back(val % 10 + '0');
	carry = val / 10;
    }
    reverse(rst.begin(), rst.end());

    return rst;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    int i = 0;
    for (i = 0; i < k; i++) {
	if (is_palindrome(s))
	    break;
	s = add(s, my_reverse(s));
    }

    cout << s << endl << i << endl;

    return 0;
}
