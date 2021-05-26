#include <iostream>
#include <unordered_map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;


int main() {
    int rst = 0, k = 2;
    for (int i = 1; i <= 10000; i++)
	rst += k % i;

    cout << rst << endl;


    return 0;
}
