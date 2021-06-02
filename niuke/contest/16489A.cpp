#include <iostream>

using namespace std;
using ll = long long;

const int N = 1e6 + 10, mod = 1e9 + 7;

char s[N];

int main() {
    char c;
    int n = 0, ya = 0, a = 0, i = 0;
    scanf("%s", s);
    while (s[i]) {
	if (s[i] == 'n') n++;
	else if (s[i] == 'a' && c == 'y') ya++, a--;
	else a++;
	c = s[i];
	i++;
    }

    int k;
    scanf("%d%s", &k, s);
    for (int i = 0; i < k; i++) {
	if (s[i] == 'N') {
	    ya = (ya + n) % mod;
	}
	else {
	    n = (n + ya) % mod;
	    ya = 0;
	}
    }

    printf("%d\n", ((ll)n + ya * 2 + a) % mod);

    return 0;
}
