#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str0, str1;
    cin >> str0 >> str1;
    bool carry = 0;
    vector<int> rst;
    int ptr0 = str0.length() - 1, ptr1 = str1.length() - 1;
    
    while (ptr0 >= 0 || ptr1 >= 0) {
	int val0, val1;
	if (ptr0 >= 0) {
	    val0 = str0[ptr0] - '0';
	    ptr0--;
	}
	else 
	    val0 = 0;
	if (ptr1 >= 0) {
	    val1 = str1[ptr1] - '0';
	    ptr1--;
	}
	else 
	    val1 = 0;
	int val = val0 + val1 + carry;
	rst.push_back(val % 10);
	carry = val / 10;
    }
    if (carry) rst.push_back(1);

    for (int i = rst.size() - 1; i >= 0; i--) {
	cout << rst[i];
    }
    cout << endl;

    return 0;
}
