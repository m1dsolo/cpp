#include <iostream>

using namespace std;

const int N = 1e5 + 10;

char s[N], map[] = "FeiMa";

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
	scanf("%d%s", &n, s);
	int cnt = 0, rst = 0;
	for (int i = 0; i < n; i++) {
	    if (s[i] == map[cnt]) {
		if (++cnt == 5) {
		    rst++;
		    cnt = 0;
		}
	    }
	}
	printf("%d\n", rst);
    }

    return 0;
}
