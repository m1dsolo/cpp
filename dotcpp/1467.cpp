// error(zuo cuo le)
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int rst = 0;
    for (int i = 0; i < n / 2; i++) {
	int index = n - i - 1;
	if (s[i] != s[index]) {
	    for (int j = index - 1; j > i; j--) {
		if (s[i] == s[j]) {
		    rst += 2 * index - 2 * j - 1;	// (right - left) + (right - left - 1)
		    swap(s[j], s[index]);
		    break;
		}
	    }
	}
    }

    int left = 0, right = n - 1;
    while (left < right) {
	if (s[left++] != s[right--]) {
	    cout << "Impossible" << endl;
	    return 0;
	}
    }

    cout << rst << endl;

    return 0; 
}
