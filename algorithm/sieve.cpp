#include <iostream>
#include <vector>

using namespace std;

void sieve(int n) {
    vector<bool> v(n + 1, true);
    v[1] = false;
    for (int i = 2; i < n; i++) {
	if (v[i]) {
	    cout << i << endl;
	    for (int j = i * i; j < n; j += i)
		v[j] = false;
	}
    }
}

int main() {
    sieve(100);

    return 0; 
}
