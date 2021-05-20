#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

const int N = 2e7 + 10;

int primes[N], visited[N];
int cnt = 0;

int main() {
    int l, r, val;
    scanf("%d %d", &l, &r);
    int rst = l <= 2 && r >= 2;
    for (int i = 2; i <= r; i++) {
	if (!visited[i]) {
	    primes[cnt++] = i;
	    if (i % 4 == 1 && i >= l)
		rst++;
	}
	for (int j = 0; j < cnt && (val = i * primes[j]) <= r; j++) {
	    visited[val] = true;
	    if (!(i % primes[j]))
		break;
	}
    }

    printf("%d\n", rst);

    return 0;
}
