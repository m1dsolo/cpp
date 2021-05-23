#include <iostream>
#include <unordered_map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;


int main() {
    vector<int> v{1, 2, 3, 4, 5}, rst(5);

    partial_sum(v.begin(), v.end(), rst.begin());

    for (int i = 0; i < 5; i++)
	cout << rst[i] << endl;


    return 0;
}
