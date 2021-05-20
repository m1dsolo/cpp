#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

int main() {
    int n;
    cin >> n;
    vector<int> primes(n + 1, true);
    primes[1] = false;

    long rst = 0;
    int tmp = sqrt(n);
    for (int i = 2; i <= tmp; i++) {
	if (primes[i]) {
	    rst += i;
	    for (int j = i * i; j <= n; j += i)
		primes[j] = false;
	}
    }
    for (int i = tmp + 1; i <= n; i++) {
	if (primes[i])
	    rst += i;
    }

    cout << rst << endl;

    return 0; 
}
