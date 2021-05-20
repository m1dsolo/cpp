#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s{1, 2, 3, 4, 5};
    auto it = s.find(3);
    set<int>::reverse_iterator rit(++it);
    while (rit != s.rend()) {
	cout << *rit << endl;
	rit++;
    }
    cout << endl;

    return 0;
}
