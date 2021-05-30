#include <iostream>

using namespace std;

int main() {
    string s = "x";
    for (int i = 0; i < s.length() - 2; i++) {	// s.length()是unsigned, -2会变溢出变非常大
    }

    return 0;
}
