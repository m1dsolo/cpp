#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int n = 2019;

vector<int> primes;
vector<bool> visited(n + 1);
unordered_set<int> set;

int main() {
    for (int i = 2; i <= n; i++) {
	if (!visited[i]) primes.push_back(i);
	for (int prime : primes) {
	    if (i * prime > n) break;
	    visited[i * prime] = true;
	    if (!(i % prime)) break;
	}
    }

    for (int i = 0; i < primes.size() - 1; i++) {
	for (int j = i + 1; j < primes.size(); j++) {
	    set.insert(primes[i] + primes[j]);
	}
    }
    cout << set.size() << endl;

    return 0;
}
