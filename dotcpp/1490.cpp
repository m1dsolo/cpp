#include <iostream>
#include <cmath>

using namespace std;

// 4150, 4151, 54748, 92727, 93084, 194979
int main() {
    for (int i = 2; i <= 194979; i++) {
	int val = i;
	int sum = 0;
	while (val) {
	    sum += pow(val % 10, 5);
	    if (sum > i) break;
	    val /= 10;
	}
	if (sum == i) {
	    cout << i << endl;
	}
    }


    return 0;
}
