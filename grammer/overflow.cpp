#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() { 
    long long a = -pow(2, 63) - 10000000, b = -pow(2, 63) - 1000000000000000, c;

    printf("%lld\n", a + b);

    return 0;
}
