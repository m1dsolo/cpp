#include <iostream>
const int n = 100;

using namespace std;

bool visit[n + 1];
int primes[n + 1];
int cnt = 0;

// O(n)
int main() {
    for (int i = 2; i <= n; i++) {
	if (!visit[i])
	    primes[cnt++] = i;
	for (int j = 0; j < cnt && i * primes[j] <= n; j++) {
	    visit[i * primes[j]] = true;
	    if (!(i % primes[j]))
		break;
	}
    }
    for (int i = 0; i < cnt; i++) {
	cout << primes[i] << endl;
    }

    return 0;
}
