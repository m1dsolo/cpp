#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    a += b;

    int digit = 0, tmp = a;
    while (tmp) {
	tmp /= 10;
	digit++;
    }

    string s = to_string(a);

    int ptr = s.length();
    for (int i = 3; i < digit; i += 3)
	s.insert(ptr -= 3, ",");

    cout << s << endl;

    return 0;
}
