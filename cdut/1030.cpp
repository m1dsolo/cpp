#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << (count(s.begin(), s.end(), 'A') % 2 ? 'A' : 'B') << endl;

    return 0;
}
