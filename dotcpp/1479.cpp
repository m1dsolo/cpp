#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
	int val;
	cin >> val;
	if (val) {
	    cout << val << " ";
	    cnt++;
	}
    }
    cout << endl << cnt << endl;

    return 0;
}
