#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

vector<int> split(const string &s) {
    vector<int> rst;
    stringstream ss(s);
    string substr;
    while (getline(ss, substr, ' '))
	rst.push_back(stoi(substr));
    return rst;
}

int main() {
    string s;
    int i = 0, cnt = 0;
    ofstream of("target");
    while (getline(cin, s)) {
	i++;
	vector<int> v = split(s);
	if (v.size() == 1) {
	    if (++cnt == 2)
		break;
	}
	of << s << endl;
    }

    cout << i << endl;

    return 0;
}
