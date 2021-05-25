#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> set;
    auto it = set.insert(2);

    cout << *it << " " << it.second << endl;

    it = set.insert(2);

    cout << *it.first << " " << it.second << endl;

    return 0;
}
