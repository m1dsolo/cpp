#include <iostream>
//#include <algorithm>
#include <map>

using namespace std;

int main() {
    map<int, int> m;

    cout << (m.upper_bound(2) == m.end()) << endl;

    return 0;
}
