#include <iostream>

using namespace std;

int main() {
    pair<int, int> p;
    int a = 1, b = 2;
    p = a > b ? {a, b} : {b, a};	// 这么写居然有问题

    cout << p.first << " " << p.second << endl;

    return 0;
}
