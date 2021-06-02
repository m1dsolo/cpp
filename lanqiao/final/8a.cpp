#include <iostream>

using namespace std;

string s = "many";
int main() {
    int rst = 0;
    for (char c : s) {
	rst = rst * 36 + c - 'a' + 10;
    }

    printf("%d\n", rst);


    return 0;
}
