#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> divisors;
void divisor_factorization(int n) {
    for (int i = 1; i <= sqrt(n); i++) {
	if (!(n % i)) {
	    divisors.emplace_back(i);
	    divisors.emplace_back(n / i);
	}
    }
} 

int main() {
    divisor_factorization(1000);
    for (int a : divisors) {
	cout << a << endl;
    }

    return 0;
}
