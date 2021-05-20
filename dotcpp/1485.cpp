#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int val) {
    for (int i = 2; i <= sqrt(val); i++) {
	if (!(val % i))
	    return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    long long rst = 1;
    int cnt = 0;
    int i = 2;
    while (1) {
	if (is_prime(i)) {
	    rst = ((rst % 50000) * (i % 50000)) % 50000;
	    if (++cnt == n) 
		break;	
	    
	}
	i++;
    }

    cout << rst << endl;

    return 0;
}
