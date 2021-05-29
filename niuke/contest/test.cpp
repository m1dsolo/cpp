#include <iostream>
#include <unordered_map>
#include <numeric>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;
using ll = long long;

string s;

int main() {
    ll arr[3] = {0};
    memset(arr, 0x3f, sizeof(ll));
    memset(arr + 1, -0x3f, sizeof(ll));

    cout << (double)arr[0] / LONG_MAX << " " << (double)arr[1] / LONG_MIN << " " << arr[2] << endl;


    return 0;
}
