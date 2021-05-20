// https://www.cnblogs.com/WAMonster/p/10118934.html

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int bel[n + 1], qs[m];

int main() {
    int size = sqrt(n);
    int bnum = size + (bool)(n % size);
    for (int i = 1; i <= bnum; i++) {
	for (int j = size * (i - 1) + 1; j <= size * i; j++)
	    bel[j] = i;
    }



    return 0;
}
