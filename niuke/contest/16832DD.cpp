#include <iostream>

using namespace std;

const int N = 1e6 + 10;

char s[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    bool rst = true;
    int a = 0, b = 0;
    for (int i = 0; i < k; i++) {
	bool zero = false, one = false;
	for (int j = i; j < n; j += k) {
	    if (s[j] == '0') zero = true;
	    else if (s[j] == '1') one = true;
	}
	if (zero && one) {
	    rst = false;
	    break;
	}
	if (zero) a++;
	else if (one) b++;
    }
    if (a > k / 2 || b > k / 2)
	rst = false;

    printf("%s\n", rst ? "Yes" : "No");

    return 0;
}
