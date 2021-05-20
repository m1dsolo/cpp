#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> set;

void helper(int n, int val) {
    int max_i = n * (n - 1) / 2;
    for (int i = 0; i <= max_i; i++) {
	set.insert(n + i + val);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
	helper()
    }
    cout << set.size() << endl;

    return 0;
}
