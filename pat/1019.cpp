#include <iostream>
#include <vector>

using namespace std;

bool is_palindrome(const vector<int> &v) {
    for (int i = 0; i < v.size() / 2; i++) {
	if (v[i] != v[v.size() - 1 - i])
	    return false;
    }
    return true;
}

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    vector<int> v;
    while (n) {
	v.emplace_back(n % b);
	n /= b;
    }

    printf("%s\n", is_palindrome(v) ? "Yes" : "No");
    for (int i = v.size() - 1; i; i--)
	printf("%d ", v[i]);
    printf("%d\n", v.front());

    return 0;
}
