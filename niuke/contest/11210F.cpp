#include <iostream>

using namespace std;
using ll = long long;

ll x, y;

void go(int a, int k) {
    switch (a % 4) {
	case 0: y += k; break;
	case 1: x += k; break;
	case 2: y -= k; break;
	case 3: x -= k; break;
    }
}

int main() {
    int t, n, k;
    char s[2];
    scanf("%d", &t);
    while (t--) {
	x = 0, y = 0;
	int a = 0;
	scanf("%d", &n);
	while (n--) {
	    scanf("%s %d", s, &k);
	    switch (s[0]) {
		case 'r': a = (a - k % 4 + 4) % 4; break;
		case 'l': a = (a + k % 4) % 4; break;
		case 'w': go(a, k); break;
		case 'd': go(a + 1, k); break;
		case 's': go(a + 2, k); break;
		case 'a': go(a + 3, k); break;
	    }
	}
	printf("%lld %lld\n", x, y);
    }

    return 0;
}
