#include <iostream>

using namespace std;

int main() {
    int m, s, t;
    scanf("%d %d %d", &m, &s, &t);

    int s1 = 0, s2 = 0, i = 1;
    for (; i <= t; i++) {
	s1 += 17;
	if (m >= 10) {
	    s2 += 60;
	    m -= 10;
	}
	else
	    m += 4;
	s1 = max(s1, s2);
	if (s1 >= s) break;
    }

    if (i <= t)
	cout << "Yes" << endl << i << endl;
    else
	cout << "No" << endl << s1 << endl;

    return 0;
}
