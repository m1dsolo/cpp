#include <iostream>
#include <set>

using namespace std;

int main() {
    set<string> set;
    string s;
    while (cin >> s) {
	set.insert(s);
    }

    cout << set.size() << endl;

    return 0; 
}
