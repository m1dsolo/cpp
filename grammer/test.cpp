#include <iostream>
#include <vector>

using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
	cout << __builtin_popcount(i) << endl;
    }

    return 0;
}
