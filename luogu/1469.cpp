#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int rst = 0;
    int tmp;
    for (int i = 0; i < n; i++) {
	scanf("%d", &tmp);
	rst ^= tmp;
    }
    cout << rst << endl;

    return 0;
}
