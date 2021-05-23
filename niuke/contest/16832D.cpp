#include <iostream>

using namespace std;

const int N = 1e6 + 10;

char arr[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    getchar();
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
	scanf("%c", &arr[i]);
    bool rst = true;
    if (k & 1)
	rst = false;
    else {
	for (int i = 0; i < k; i++) {
	    if (i + k == n) break;
	    if (arr[i] == '?')
		arr[i] = arr[i + k];
	}
	for (int i = n - 1; i >= 0; i--) {
	    if (i - k < 0) break;
	    if (arr[i] == '?')
		arr[i] = arr[i - k];
	}
	int zero = 0, one = 0, q = 0;
	for (int i = 0; i < n; i++) {
	    switch (arr[i]) {
		case '0': zero++; break;
		case '1': one++; break;
		case '?': q++; break;
	    }
	    if (i >= k) {
		switch (arr[i]) {
		    case '0': zero--; break;
		    case '1': one--; break;
		    case '?': q--; break;
		}
	    }
	    if (i >= k - 1 && abs(zero - one) > q) {
		cout << i << " " << abs(zero - one) << " " << q << endl;
		rst = false;
		break;
	    }
	}
    }

    printf("%s\n", arr);
    printf("%s\n", rst ? "Yes" : "No");

    return 0;
}
