#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

const int N = 1e6 + 10;

int primes[N], cnt, ps[N], sz;
bool visited[N];

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
	if (!visited[i]) primes[cnt++] = i;
	for (int j = 0; primes[j] * i <= n; j++) {
	    visited[primes[j] * i] = true;
	    if (!(i % primes[j])) break;
	}
    }
}

int main() {
    sieve(5e4);
    int l, r;
    while (scanf("%d %d", &l, &r) != EOF) {
	memset(ps, 0, sizeof(ps)); sz = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < cnt; i++) {
	    int p = primes[i];
	    for (ll j = max(((ll)l + p - 1) / p * p, 2ll * p); j <= r; j += p)    // 2p防止把自己这个质数筛掉，(l + p - 1) / p是(l / p)的上取整
		visited[j - l] = true;
	}
	for (int j = 0; j <= r - l; j++)
	    if (!visited[j] && l + j > 1) ps[sz++] = l + j;
	if (sz < 2)
	    puts("There are no adjacent primes.");
	else {
	    int minp = 0, maxp = 0;
	    for (int j = 0; j + 1 < sz; j++) {
		int d = ps[j + 1] - ps[j];
		if (d < ps[minp + 1] - ps[minp]) minp = j;
		if (d > ps[maxp + 1] - ps[maxp]) maxp = j;
	    }
	    printf("%d,%d are closest, %d,%d are most distant.\n", ps[minp], ps[minp + 1], ps[maxp], ps[maxp + 1]);
	}
    }

    return 0;
}
