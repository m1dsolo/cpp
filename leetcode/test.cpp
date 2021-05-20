#include <iostream>

using namespace std;

void helper(int n) {
    cout << n << endl;
}

int main() {
    int n = 9;
    helper(n--);
    return 0;
}
