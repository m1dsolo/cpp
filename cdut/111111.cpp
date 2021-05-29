#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string a, b;
    while (n--) {
	cin >> a >> b;
	cout << (int)a.rfind(b) << endl;
    }

    return 0;
}
