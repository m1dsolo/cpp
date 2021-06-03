#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e4;

int primes[N], sz, rst[N], cnt;
bool visited[N];

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
	if (!visited[i]) primes[sz++] = i;
	for (int j = 0; j < sz && primes[j] * i <= n; j++) {
	    visited[primes[j] * i] = true;
	    if (!(i % primes[j])) break;
	}
    }
}

bool is_prime(int n) {
    if (n < N) return !visited[n];
    if (n % 6 != 1 && n % 6 != 5) return false;
    for (int i = 5; i <= n / i; i++)
	if (!(n % i) || !(n % (i + 2))) return false;
    return true;
}

void dfs(int last, int prod, int s) {
    if (s == 1)
	rst[cnt++] = prod;
    else {
	if (s - 1 > (last >= 0 ? primes[last] : 0) && is_prime(s - 1))
	    rst[cnt++] = prod * (s - 1);
	for (int i = last + 1; primes[i] <= s / primes[i]; i++) {
	    for (int j = 1 + primes[i], k = primes[i]; j <= s; k *= primes[i], j += k) {
		if (!(s % j)) dfs(i, prod * k, s / j);
	    }
	}
    }
}

int main() {
    sieve(N - 1);
    int n;
    while (scanf("%d", &n) != EOF) {
	dfs(-1, 1, n);
	printf("%d\n", cnt);
	sort(rst, rst + cnt);
	if (cnt) {
	    for (int i = 0; i < cnt; i++)
		printf("%d ", rst[i]);
	    printf("\n");
	    cnt = 0;
	}
    }

    return 0;
}
