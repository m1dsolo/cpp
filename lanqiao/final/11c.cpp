#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int arr[101];

bool is_prime(int n) {
    if (n <= 3) return n > 1;
    if (n % 6 != 1 && n % 6 != 5) return false;
    int max_i = sqrt(n);
    for (int i = 5; i <= max_i; i += 6) {
	if (!(n % i) || !(n % (i + 2))) return false;
    }
    return true;
}

int main() {
    for (int i = 2; i <= 100; i++) {
	int n = i;
	int a = 2;
	while (n != 1) {
	    if (is_prime(a) && !(n % a)) {
		arr[a]++;
		n /= a;
	    }
	    else
		a++;
	}
    }

    unsigned long long rst = 1;
    for (int i = 2; i <= 97; i++)
	rst *= (arr[i] + 1);

    cout << rst << endl;

    return 0;
}
