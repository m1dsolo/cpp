#include <iostream>
#include <algorithm>

using namespace std;

// 输入一个字符'a'也会覆盖掉b的值(输出 a 1 0)
int main() {
    int a = 1;
    char s;
    int b = 2;
    scanf("%s", &s);

    cout << s << " " << a << ' ' << b << endl;

    return 0;
}
