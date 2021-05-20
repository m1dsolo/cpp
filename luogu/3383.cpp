// RE

#include <cstdio>
#include <vector>

using namespace std;

bool not_prime[10000001];
int primes[700000];
int main() {
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
	if (!not_prime[i])
	    primes[cnt++] = i;
	for (int j = 0; j < cnt && i * primes[j] <= n; j++) {
	    not_prime[i * primes[j]] = true;
	    if (!(i % primes[j]))
		break;
	}
    }

    int index;
    for (int i = 0; i < q; i++) {
	scanf("%d", &index);
	printf("%d\n", primes[index - 1]);
    }

    return 0;
}
