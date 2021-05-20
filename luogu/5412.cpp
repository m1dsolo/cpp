#include <iostream>
#include <algorithm>

using namespace std;

pair<double, bool> arr[10010];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> m;
    for (int i = 0; i < m; i++) {
	cin >> n;
	for (int i = 0; i < n; i++)
	    cin >> arr[i].second;
	for (int i = 0; i < n; i++)
	    cin >> arr[i].first;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
	    if (!arr[i].second)
		cout << arr[i].first << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
	    if (arr[i].second)
		cout << arr[i].first << " ";
	}
	cout << endl;
    }

    return 0;
}
