#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long n = 2021041820210418;

int main() {
    vector<long long> v;
    for (int i = 1; i <= sqrt(n); i++) {
	if (!(n % i)) {
	    v.push_back(i);
	    v.push_back(n / i);
	}
    }

    int rst = 0;
    for (long long a : v) {
	for (long long b : v) {
	    for (long long c : v) {
		if (a * b * c == n)
		    rst++;
	    }
	}
    }

    cout << rst << endl;

    return 0;
}
