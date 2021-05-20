#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int main() {
    //ifstream ifs("data");
    int k;
    cin >> k;
    cin.get();
    //ifs >> k;
    //ifs.get();
    string s;
    getline(cin, s);
    //getline(ifs, s);
    vector<int> alices, bobs;
    int index = 0;
    while ((index = s.find("Alice", index)) != string::npos) {
	if (!isalpha(s[index + 5]))
	    alices.push_back(index);
	index++;
    }
    index = 0;
    while ((index = s.find("Bob", index)) != string::npos) {
	if (!isalpha(s[index + 3]))
	    bobs.push_back(index);
	index++;
    }

    long long rst = 0;
    int ptr = 0;
    for (int i = 0; i < bobs.size(); i++) {
	while (bobs[i] > alices[ptr] + 25) {
	    if (++ptr == alices.size())
		break;
	}
	int a = alices[ptr];
	if (a - 23 <= bobs[i] && bobs[i] <= a + 25)
	    rst++;
    }

    cout << rst << endl;

    //ifs.close();

    return 0;
}
