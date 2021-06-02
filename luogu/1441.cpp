#include <iostream>
#include <bitset>

using namespace std;


int arr[30];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);
    int rst = 0;
    for (int i = 0; i < (1 << n); i++) {
	if (__builtin_popcount(i) == n - m) {
	    bitset<2010> S;
	    S[0] = 1;
	    for (int j = 0; j < n; j++) {
		if (i & (1 << j))
		    S |= S << arr[j];
	    }
	    rst = max(rst, (int)S.count() - 1);
	}
    }

    printf("%d\n", rst);

    return 0;
}
