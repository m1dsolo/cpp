#include<iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    string s;
    while (cin >> s) {
	bool rst = true;
        string strs[4];
        int point_num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') {
                if (++point_num == 4) {
		    rst = false;
                    break;
                }
	    }
            else strs[point_num] += s[i];
        }

        for (int i = 0; i < 4; i++) {
            int val = atoi(strs[i].c_str());
            if (!val && strs[i] != "0") {
		rst = false;
                break;
            }
            if (val > 255 || val < 0) {
		rst = false;
                break;
            }
        }
	if (rst)
	    cout << "Y" << endl;
	else
	    cout << "N" << endl;
    }
    return 0;

}
