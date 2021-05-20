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

    int i = 2;
    int rst = 1;
    while (n != i) {
	if (!(n % i) && is_prime(i)) {
	    n /= i;
	    cout << i << " ";
	    rst ++;
	}
	else
	    i++;
    }
    cout << i << endl << rst << endl;

    return 0;
}
