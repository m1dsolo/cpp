#include <iostream>

using namespace std;

int main() {
    string name, input;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> input;
	if (input == "heyhiri")
	    cout << "hey" << (name == "" ? "sunny" : name) << endl;
	else if (input == "whoami")
	    cout << (name == "" ? "sunny" : "handsome" + name) << endl;
	else if (input.substr(0, 3) == "iam") {
	    name = input.substr(3, input.length() - 3);
	    cout << "yessir" << endl;
	}
	else
	    cout << "idontunderstand" << endl;
    }

    return 0;
}
