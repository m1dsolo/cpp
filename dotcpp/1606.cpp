#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    set<int> s0, s1;
    for (int i = 0; i < 2; i++) {
	int n; cin >> n;
	for (int j = 0; j < n; j++) {
	    int val; cin >> val;
	    if (i) s1.insert(val);
	    else s0.insert(val);
	}
    }

    set<int> a, b, c;
    set_intersection(s0.begin(), s0.end(), s1.begin(), s1.end(), inserter(a, a.begin()));
    set_union(s0.begin(), s0.end(), s1.begin(), s1.end(), inserter(b, b.begin()));
    set_difference(s0.begin(), s0.end(), s1.begin(), s1.end(), inserter(c, c.begin()));

    for (set<int>::iterator it = a.begin(); it != a.end(); it++) 
	cout << *it << " ";
    cout << endl;
    for (set<int>::iterator it = b.begin(); it != b.end(); it++) 
	cout << *it << " ";
    cout << endl;
    for (set<int>::iterator it = c.begin(); it != c.end(); it++) 
	cout << *it << " ";
    cout << endl;

    return 0;
}
