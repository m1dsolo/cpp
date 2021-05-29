#include <iostream>

using namespace std;

const int N = 100;
string s = "78345123451234512";
int nexts[N];

void get_next (int len) {
    int i=0,j=-1;
    nexts[0] = -1;

    while(i<len){
	if(j==-1 || s[i]==s[j]){
	    i++;j++;
	    nexts[i] = j;
	}else
	    j = nexts[j];
    }
}

int main() {
    int n = s.length();
    get_next(n);
    for (int i = 0; i < n; i++)
	cout << nexts[i] << " ";
    cout << endl;

    cout << n - nexts[n] << " " << n / (n - nexts[n]) << endl;
    //for (int i = 2; i < n; i++) {
	//if (!(i % (i - nexts[i])) && nexts[i]) {
	    //// 
	    //cout << i << " " << i - nexts[i] << " " << i / (i - nexts[i]) << endl;
	//}
    //}

    return 0;
}
