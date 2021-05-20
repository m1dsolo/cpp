#include <iostream>

using namespace std;

int helper(int val) {
    int rst = 0;
    for (int i = 1; i < val; i++) {
	if (!(val % i))
	    rst += i;
    }

    return rst;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << ((helper(a) == b && helper(b) == a) ? "yes" : "no") << endl;

    return 0;
}
