#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int input(string &s, int n) {
    int rst = 0;
    for (char c : s) {
	rst = rst * n + (isdigit(c) ? c - '0' : c - 'A' + 10);
    }
    return rst;
}

string output(int val, int m) {
    stringstream ss;
    while (val) {
	int mod = val % m;
	if (mod > 9)
	    ss << (char)('A' + mod - 10);
	else
	    ss << mod;
	val /= m;
    }
    string rst = ss.str();
    reverse(rst.begin(), rst.end());
    return rst;
}

int main() {
    int n, m;
    string s;
    cin >> n >> s >> m;
    cout << output(input(s, n), m) << endl;

    return 0;
}
