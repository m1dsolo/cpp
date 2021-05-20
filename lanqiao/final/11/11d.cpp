#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> primes;
void sieve(int n) {
    vector<bool> visited(n + 1);
    for (int i = 2; i <= n; i++) {
	if (!visited[i]) primes.emplace_back(i);
	for (int prime : primes) {
	    if (i * prime > n) break;
	    visited[i * prime] = true;
	    if (!(i % prime)) break;
	}
    }
}
int main() {
    sieve(100000);
    int n = 2;
    while (n < 10) {
	int val = n;
	int rst = 1;
	int cnt = 0;
	int i = 0;
	while (val != 1) {
	    while (val != 1 && !(val % primes[i])) {
		val /= primes[i];
		cnt++;
	    }
	    rst *= (cnt + 1);
	    i++;
	    cnt = 0;
	}
	rst *= (cnt + 1);
	cout << n << " " << rst << endl;
	if (rst == 100)
	    break;
	n++;
    }
    cout << n << endl;

    return 0;
}
