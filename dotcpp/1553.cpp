#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    int tmp = sqrt(n);
    for (int i = 2; i <= tmp; i++) {
	if (!(n % i))
	    return false;
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++) {
	arr[s[i] - 'a']++;
    }

    int max_num = INT_MIN, min_num = INT_MAX;
    for (int i = 0; i < 26; i++) {
	if (!arr[i])
	    continue;
	max_num = max(max_num, arr[i]);
	min_num = min(min_num, arr[i]);
    }

    int dif = max_num - min_num;
    if (is_prime(dif)) {
	cout << "Lucky Word" << endl << dif << endl;
    }
    else
	cout << "No Answer" << endl << 0 << endl;

    return 0;
}
