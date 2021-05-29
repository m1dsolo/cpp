#include <iostream>

using namespace std;

void dfs(int p, int q) {
    if (!(p % q))
	cout << p / q;
    else {
	cout << '{' << p / q << "+1/";
	dfs(q, p % q);
	cout << '}';
    }
}
int main() {
    ios::sync_with_stdio(false);
    int t, p, q;
    cin >> t;
    while (t--) {
	cin >> p >> q;
	cout << p << '/' << q << " = ";
	if (p % q) {
	    cout << p / q << "+1/";
	    dfs(q, p % q);
	}
	else
	    cout << p / q;
	cout << endl;
    }

    return 0;
}
