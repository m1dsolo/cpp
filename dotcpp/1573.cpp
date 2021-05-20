#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

//int main() {
    //string s = "123456789";
    //do {
	//for (int i = 1; i <= 4; i++) {
	    //int val = stoi(s.substr(0, i));
	    //int tmp = val;
	    //stringstream stream;
	    //while (stream.str().size() < 9) {
		//stream << tmp;
		//tmp += val;
	    //}
	    //if (stream.str() == s) {
		//cout << s << endl;
	    //}
	//}
    //} while (next_permutation(s.begin(), s.end()));

    //return 0;
//}

int main() {
    string s = "671234589";
    cout << "123456789" << endl;
    cout << "192384576" << endl;
    cout << "219438657" << endl;
    cout << "273546819" << endl;
    cout << "327654981" << endl;
    do {
	for (int i = 1; i <= 4; i++) {
	    int val = stoi(s.substr(0, i));
	    int tmp = val;
	    stringstream stream;
	    while (stream.str().size() < 9) {
		stream << tmp;
		tmp += val;
	    }
	    if (stream.str() == s) {
		cout << s << endl;
	    }
	}
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}
