#include <iostream>

using namespace std;

int n;
inline void print_line(int a) {
    for (int i = 0; i < a; i++)
	cout << '*';
    for (int i = 0; i < n - 2 * a; i++)
	cout << 'A';
    for (int i = 0; i < a; i++)
	cout << '*';
    cout << endl;
}

int main() {
    cin >> n;
    if (!(n % 2))
	cout << 'N' << endl;
    else {
	for (int i = n / 2; i >= 0; i--)
	    print_line(i);
	for (int i = 1; i <= n / 2; i++)
	    print_line(i);
    }

    return 0;
}
