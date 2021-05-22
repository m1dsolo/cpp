#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string key, val;
    vector<pair<string, string>> rst;
    for (int i = 0; i < n; i++) {
	cin >> key >> val;
	bool flag = false;
	for (char &c : val) {
	    switch (c) {
		case '1': c = '@'; flag = true; break;
		case '0': c = '%'; flag = true; break;
		case 'l': c = 'L'; flag = true; break;
		case 'O': c = 'o'; flag = true; break;
	    }
	}
	if (flag)
	    rst.push_back({key, val});
    }

    if (rst.size()) {
	cout << rst.size() << endl;
	for (const auto p : rst) {
	    cout << p.first << " " << p.second << endl;
	}
    }
    else if (n == 1)
	cout << "There is 1 account and no account is modified" << endl;
    else
	cout << "There are " << n << " accounts and no account is modified" << endl;

    return 0;
}
