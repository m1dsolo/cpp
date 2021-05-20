#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    long long rst = 0;
    for (int k = 1; k <= n; k++) {
	int left = 0, right = 0;
	int set[26] = {0};
	int valid = 0;
	while (right < n) {
	    if (!set[s[right++] - 'a']++) valid++;
	    if (right - left > k) {
		if (!--set[s[left++] - 'a']) valid--;
	    }
	    if (right - left == k)
		rst += valid;
	}
    }
    cout << rst << endl;

    return 0;
}
