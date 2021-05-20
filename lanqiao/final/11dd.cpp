#include <iostream>
#include <set>

using namespace std;

// rst = 3616159, 要跑十多秒
int main() {
    string s;
    cin >> s;
    set<string> set;
    for (char c : s) {
	for (const string &s : set) {
	    if (c > s.back()) {
		set.insert(s + c);
	    }
	}
	set.insert(string {c});
    }

    cout << set.size() << endl;

    return 0;
}
