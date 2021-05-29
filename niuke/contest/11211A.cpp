#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

char s[N], tail[N];
int size;

int main() {
    int n;
    scanf("%d%s", &n, s);

    tail[size++] = s[0];
    for (int i = 1; i < n; i++) {
	if (s[i] >= tail[size - 1])
	    tail[size++] = s[i];
	else
	    *upper_bound(tail, tail + size, s[i]) = s[i];
    }

    printf("%d\n", n - size);

    return 0;
}
