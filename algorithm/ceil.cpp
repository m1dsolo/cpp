#include <iostream>

using namespace std;

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    cout << ceil(5, 2) << endl;

    return 0;
}
