#include <iostream>

using namespace std;

const int N = 1e3 + 10;

bool a1[N], a2[N];

int main() {
    int n, x;
    while (scanf("%d %d", &n, &x) != EOF) {
	for (int i = 1; i <= n; i++)
	    scanf("%d", &a1[i]);
	for (int i = 1; i <= n; i++)
	    scanf("%d", &a2[i]);
	bool rst = false;
	if (a1[1]) {
	    if (a1[x]) rst = true;
	    else if (a2[x]) {
		for (int i = x + 1; i <= n; i++)
		    if (a1[i] && a2[i]) {
			rst = true;
			break;
		    }
	    }
	}
	printf("%s\n", rst ? "YES" : "NO");
    }

    return 0;
}
