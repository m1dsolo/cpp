#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int val) {
    int tmp = sqrt(val);
    for (int i = 2; i <= tmp; i++) {
	if (!(val % i))
	    return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
	int val;
	cin >> val;
	bool ok = false;
	int j = 2;
	while (j <= val / 2) {
	    if (!(val % j) && is_prime(j)) {
		ok = is_prime(val / j);
		break;
	    }
	    j++;
	}

	cout << ((ok) ? "Yes" : "No") << endl;
    }

    return 0;
}
