#include <iostream>

using namespace std;

int main() {
    string s;
    int rst = 0;
    for (int i = 0; i < 5; i++) {
	cin >> s;
	if (s[0] == s[2] && s[1] == s[3] - 1) rst++;
    }

    printf("%d\n", rst);

    return 0;
}
