#include <iostream>

using namespace std;

int main() {
    int v1, v2, t, s, l1;
    cin >> v1 >> v2 >> t >> s >> l1;
    int l2 = l1;

    int rst = 0;
    int stop = 0;
    while (l1 > 0 && l2 > 0) {
	if (l1 + t <= l2 && !stop)
	    stop = s;
	if (stop)
	    stop--;
	else
	    l1 -= v1;
	l2 -= v2;
	rst++;
    }

    if (l1 <= 0 && l2 <= 0)
	cout << "D" << endl;
    else if (l1 <= 0)
	cout << "R" << endl;
    else 
	cout << "T" << endl;

    cout << rst << endl;

    return 0;
}
