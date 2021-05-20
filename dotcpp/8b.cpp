#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstring>

using namespace std;

const int n = 1000000;
bool visited[n];

int main() {
    vector<int> primes;
    unordered_set<int> set;
    for (long i = 2; i < n; i++) {
	if (!visited[i]) {
	    primes.push_back(i);
	    set.insert(i);
	}
	for (long j = 0; j < primes.size() && i * primes[j] < n; j++) {
	    visited[i * primes[j]] = true;
	    if (!(i % primes[j]))
		break;
	}
    }

    int rst = 1;
    while (1) {
	cout << rst << endl;
	int flag = false;
	for (int prime : primes) {
	    int i = 1;
	    for (; i < 10; i++) {
		if (set.find(prime += rst) == set.end())
		    break;
	    }
	    if (i == 10) {
		flag = true;
		break;
	    }
	}
	if (flag)
	    break;
	rst++;
    }

    cout << rst << endl;

    return 0;
}
