#include <iostream>
#include <vector>

using namespace std;

typedef struct arr {
    int a[4];
} Arr;

int main() {
    int n;
    cin >> n;
    vector<Arr> carpets;
    for (int i = 0; i < n; i++) {
	Arr arr;
	cin >> arr.a[0] >> arr.a[1] >> arr.a[2] >> arr.a[3];
	carpets.push_back(arr);
    }
    int x, y;
    cin >> x >> y;

    for (int i = carpets.size() - 1; i >= 0; i--) {
	Arr arr = carpets[i];
	if (x >= arr.a[0] && x <= arr.a[0] + arr.a[2] && y >= arr.a[1] && y <= arr.a[1] + arr.a[3]) {
	    cout << i + 1 << endl;
	    return 0;
	}
    }

    cout << -1 << endl;
    return 0;
}
