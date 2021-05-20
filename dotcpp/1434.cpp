#include <iostream>

using namespace std;

int n;

bool is_ok(int a) {
    int b = 0;
    int sum = 0;
    int val = a;
    while (val) {
	int digit = val % 10;
	sum += digit;
	b = b * 10 + digit;
	val /= 10;
    }

    return b == a && sum == n;
}

int main() {
    cin >> n;
    
    bool flag = false;
    for (int i = 10000; i < 1000000; i++) {
	if (is_ok(i)) {
	    cout << i << endl;
	    flag = true;
	}	    
    }
    if (!flag)
	cout << -1 << endl;

    return 0; 
}
