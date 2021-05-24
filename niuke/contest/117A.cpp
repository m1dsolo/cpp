#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    string s;
    cin >> t;
    while (t--) {
	cin >> n;
	bool rst = true;
	while (n--) {
	    cin >> s;
	    if (s != "PERFECT")
		rst = false;
	}
	printf("%s\n", rst ? "MILLION Master" : "NA Noob");
    }

    return 0;
}
