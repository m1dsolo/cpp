// 为什么resize之后push_back"bbb"与输入之间没有空格？
// 为什么把resize换成reverse之后输入的全被盖掉了？
// resize，和reverse内部实现？
#include <iostream>
#include <vector>

using namespace std;

struct sb {
    string s;
} sbs[2];

int main() { 
    sbs[0].s.resize(5);

    scanf("%s", &sbs[0].s[0]);
    //sbs[0].s.push_back('b');
    sbs[0].s += "bbb";
    cout << sbs[0].s << endl << sbs[0].s.length() << endl;

    return 0;
}
