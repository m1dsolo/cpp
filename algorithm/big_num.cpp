#include <iostream>
#include <algorithm>

using namespace std;

//class BigNum {
//private:
    //int d[1000] = {0};
    //int len = 0;
    //int sign = 1;
//public: 
    //BigNum() {}
    //BigNum(const string &s) {
	//sign = (s[0] != '-');
	//len = s.length();
	//for (int i = len - 1; i >= !sign; i--) {
	    //d[len - 1 - i] = s[i] - '0';
	//}
    //}
    //BigNum operator+(const BigNum &b) {
	//BigNum rst;
	//int carry = 0;
	//int tmp;
	//for (int i = 0; i < this->len || i < b.len; i++) {
	    //tmp = this->d[i] + b.d[i] + carry;
	    //rst.d[rst.len++] = tmp % 10;
	    //carry = tmp / 10;
	//}
	//if (carry)
	    //rst.d[rst.len++] = 1;

	//return rst;
    //}
    //BigNum operator-(const BigNum &b) {
	//BigNum rst;
	//rst.sign = 
    //}
    //BigNum operator*(const BigNum &b) {
	//BigNum rst;
	//for (int i = 0; i < this->len || )
    //}
    //bool operator<(const BigNum &b) {
	//if (len < b.len) return true;
	//else if (len > b.len) return false;
	//else {
	    //for (int i = len - 1; i >= 0; i--) {
		//if (d[i] < b.d[i])
		    //return true;
	    //}

	//}
    //}
//};

string add(const string &s1, const string &s2) {
    string rst;
    int m = s1.length() - 1, n = s2.length() - 1;
    int carry = 0;
    while (m >= 0 || n >= 0) {
	int a = (m >= 0 ? s1[m--] - '0' : 0);
	int b = (n >= 0 ? s2[n--] - '0' : 0);
	rst.push_back((a + b + carry) % 10 + '0');
	carry = (a + b + carry) / 10;
    }
    if (carry)
	rst.push_back('1');
    reverse(rst.begin(), rst.end());

    return rst;
}

int main() {
    cout << add("12345", "6789") << endl;

    return 0;
}
