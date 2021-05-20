#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int a = 3, b = 3;
    bool flag = true;

    cout << (a < b ^ flag) << endl;

    return 0;
}
