#include <iostream>

using namespace std;

int get_lcm(int a, int b) {
    int product = a * b;
    if (a < b) {
	int tmp = a;
	a = b;
	b = tmp;
    }

    while (int rem = a % b) {
	a = b;
	b = rem;
    }
    
    return product / b;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << get_lcm(get_lcm(a, b), c) << endl;

    return 0;
}
