#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    int max_i = sqrt(n);
    vector<int> factors;
    for (int i = 1; i < max_i; i++) {
	if (!(n % i)) {
	    factors.emplace_back(i);
	    factors.emplace_back(n / i);
	}
    }
    if ((long long)max_i * max_i == n)
	factors.emplace_back(max_i);

    for (int factor : factors)
	cout << factor << endl;

    return 0;
}
