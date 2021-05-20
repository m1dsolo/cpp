#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double rst = 0;;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
	string name;
	cin >> name;
	double price;
	cin >> price;
	int num;
	cin >> num;

	rst += price * num;
    }

    cout << setiosflags(ios::fixed) << setprecision(6) << rst << endl;

    return 0;
}
