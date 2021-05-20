#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> primes;

void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    for (int i = 2; i <= n; i++) {
	if (is_prime[i]) 
	    primes.push_back(i);
	for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
	    is_prime[i * primes[j]] = false;
	    if (!(i % primes[j]))
		break;
	}
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    sieve(b);

    for (int i = a; i <= b; i++) {
	int val = i;
	stringstream rst;
	rst << val << "=";
	int j = 0;
	while (val != primes[j]) {
	    if (!(val % primes[j])) {
		val /= primes[j];
		rst << primes[j] << '*';
	    }
	    else
		j++;
	}
	rst << primes[j];
	cout << rst.str() << endl;
    }

    return 0;
}
