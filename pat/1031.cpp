#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length(), k = (n + 2) / 3, max_j = n - 2 * k;
    for (int i = 0; i < k - 1; i++) {
	cout << s[i];
	for (int j = 0; j < max_j; j++)
	    cout << " ";
	cout << s[n - 1 - i] << endl;
    }
    for (int i = k - 1; i <= n - k; i++)
	cout << s[i];
    cout << endl;

    return 0;
}
