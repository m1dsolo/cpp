#include <iostream>

using namespace std;

int main() {
    long val;
    while (cin >> val) {
	int rst = 0;
	while (val) {
	    rst += val % 10;
	    val /= 10;
	}	
	cout << rst << endl;
    }

    return 0;
}
