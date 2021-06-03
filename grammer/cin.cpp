#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s + 1;	// 怎么实现？

    cin >> &s[0];	// 这样不行，s.length()会为0，cin到容器的原理是什么？？？

    return 0;
}
