#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size_a, size_b;
    cin >> size_a >> size_b;
    vector<int> a, b;
    a.reserve(size_a);
    b.reserve(size_b);
    for (int i = 0; i < size_a; i++) {
	int val;
	cin >> val;
	a.push_back(val);
    }
    for (int i = 0; i < size_b; i++) {
	int val;
	cin >> val;
	b.push_back(val);
    }
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
	int index = m + i;
	if (index < a.size())
	    a[m + i] = b[i];
	else
	    a.push_back(b[i]);
    }

    for (int i = 0; i < a.size() - 1; i++) {
	cout << a[i] << ",";
    }
    cout << a.back() << endl;

    return 0;
}
