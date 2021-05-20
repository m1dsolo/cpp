#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string add(const string &s1, const string &s2) {
    string rst;
    int m = s1.length() - 1, n = s2.length() - 1, carry = 0;
    while (m >= 0 || n >= 0) {
	int a = (m >= 0 ? s1[m--] - '0' : 0);
	int b = (n >= 0 ? s2[n--] - '0' : 0);
	rst.push_back((a + b + carry) % 10 + '0');	
	carry = (a + b + carry) / 10;
    }
    if (carry)
	rst.push_back('1');
    reverse(rst.begin(), rst.end());

    return rst;
}

vector<int> get_map(const string &s) {
    vector<int> rst(10);
    for (char c : s)
	rst[c - '0']++;
    return rst;
}

int main() {
    string s1, s2;
    cin >> s1;
    s2 = add(s1, s1);
    vector<int> v1 = get_map(s1), v2 = get_map(s2);
    cout << (v1 == v2 ? "Yes" : "No") << endl << s2 << endl;

    return 0;
}
