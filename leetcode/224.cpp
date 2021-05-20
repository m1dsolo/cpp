#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str = "(1 + (4 + 5 + 2) - 3) + (6 + 8)";
    stack<char> s;

    int rst = 0, num = 0, sign = 1;
    for (char c : str) {
	if (isdigit(c)) {
	    num = num * 10 + c - '0';
	}
	else if (c == '+' || c == '-') {
	    rst += sign * num;
	    num = 0;
	    sign = (c == '+') ? 1 : -1;
	}
	else if (c == '(') {
	    s.push(rst);
	    s.push(sign);
	    rst = 0;
	    sign = 1;
	}
	else if (c == ')') {
	    rst += sign * num;
	    num = 0;
	    rst *= s.top(); s.pop();
	    rst += s.top(); s.pop();
	}
    }

    rst += sign * num;

    cout << rst << endl;

    return 0;
}
