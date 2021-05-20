// not right, i dont want to do this problem
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int rst = a * b;
    if (a < 10 || b < 10) {
	if (a / 10) {
	    cout << " " << a << endl;
	    cout << "×" <<  " " << b << endl;
	    cout << "━━━" << endl;
	}
	if (rst / 100)
	    cout << rst << endl;
	else if (rst / 10)
	    cout << " " << rst << endl;
	else
	    cout << "  " << rst << endl;
    }
    else {
	int rst_a = (b % 10) * a;
	int rst_b = (b / 10) * a;
	cout << "  " << a << endl;
	cout << " ×" << b << endl;
	cout << " ━━━" << endl;
	if (rst_a / 100)
	    cout << " " << rst_a << endl;
	else
	    cout << "  " << rst_a << endl;
	if (rst_b / 100)
	    cout << rst_b << " " << endl;
	else
	    cout << " " << rst_b << " " << endl;
	cout << "━━━" << endl;
	cout << rst << endl;
    }
    
    return 0;
}
