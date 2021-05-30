#include <iostream>

using namespace std;
using ll = unsigned long long;

inline int get_radix(char c) {
    return c - (isdigit(c) ? '0' : 'a' - 10);
}

ll get_val(string &s, int radix) {
    ll rst = 0;
    for (char c : s)
	rst = rst * radix + get_radix(c);
    return rst;
}

int get_min_radix(string &s) {
    int rst = 0;
    for (char c : s)
	rst = max(rst, get_radix(c));
    return rst + 1;	    // 注意+1
}

int find_radix(string &s, ll val) {
    int rst = 0;
    for (int i = get_min_radix(s); i <= 35; i++) {
	if (val == get_val(s, i)) {
	    rst = i;
	    break;
	}
    }
    return rst;
}
int main() {
    string s1, s2;
    int tag, radix;
    cin >> s1 >> s2;
    scanf("%d %d", &tag, &radix);

    int rst = tag == 1 ? find_radix(s2, get_val(s1, radix)) : find_radix(s1, get_val(s2, radix));

    cout << (rst ? to_string(rst) : "Impossible") << endl;

    return 0;
}
