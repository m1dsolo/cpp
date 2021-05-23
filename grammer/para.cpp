#include <iostream>
#include <algorithm>

using namespace std;

void helper(int a, int b) {
    printf("%d %d\n", a, b);
}

int main() {
    int n = 3;
    helper(n, n++);
    // helper(n++, n);

    return 0;
}
