#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

double a, b, c, d;

double f(double x) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

double df(double x) {
    return 3 * a * pow(x, 2) + 2 * b * x + c;
}

double newton_method(double x) {
    double tmp = x - f(x) / df(x);
    if (abs(tmp - x) < 0.005) 
	return tmp;
    else
	return newton_method(tmp);
}

int main() {
    cin >> a >> b >> c >> d;
    
    vector<double> rst;
    for (int i = -100; i <= 100; i++) {
	double val = newton_method(i);
	if (!rst.size())
	    rst.push_back(val);
	else { 
	    bool flag = true;
	    for (int i = 0; i < rst.size(); i++) {
		if (abs(val - rst[i]) < 1)
		    flag = false;
	    }
	    if (flag)
		rst.push_back(val);
	}	    
    }

    sort(rst.begin(), rst.end());
    cout << setiosflags(ios::fixed) << setprecision(2);
    for (int i = 0; i < rst.size(); i++) {
	cout << rst[i] << " ";
    }
    cout << endl;

    return 0;
}
