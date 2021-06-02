#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bit>

using namespace std;

int main() {
    for (int i = 1; i < 5; i++) {
	cout << popcount(i) << endl;
    }

    return 0;
}
