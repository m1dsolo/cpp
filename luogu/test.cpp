#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

struct item {
    int v;
    int w;
    bool flag;	// 1为多重背包
} items[N];

int main() {
    int a, b;
    char c = ':';
    cin >> a >> ':' >> b;
    cout << a << " " << b << endl;

    return 0;
}
