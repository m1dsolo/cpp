#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int map[26] = {0};
    for (char c : s) {
	map[c - 'a']++;
    }
    int max_val = 0;
    int min_val = 1000;
    for (int i = 0; i < 26; i++) {
	if (map[i]) {
	    max_val = max(max_val, map[i]);
	    min_val = min(min_val, map[i]);
	}
    }

    cout << max_val - min_val << endl;

    return 0;
}
