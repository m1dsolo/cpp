#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int k;
    long long n;
    cin >> k;
    for (int i = 0; i < k; i++) {
	scanf("%lld", &n);
	cout << (long long)(((double)n + 1) / 2 * ((n & (-n)) << (bitset<64>(n).count() - 1))) << endl;
    }

    return 0;
}
