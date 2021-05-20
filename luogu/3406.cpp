#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int arr[N][3];
int diff[N];

int main() {
    int n, m, p1, p2;
    scanf("%d %d", &n, &m);
    scanf("%d", &p1);
    for (int i = 1; i < m; i++) {
	scanf("%d", &p2);
	diff[min(p1, p2)]++;
	diff[max(p1, p2)]--;	
	p1 = p2;
    }

    for (int i = 1; i < n; i++) {
	scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }

    long long rst = 0;
    for (int i = 1; i <= n; i++) {
	diff[i] += diff[i - 1];
	rst += min((long long)arr[i][0] * diff[i], (long long)arr[i][1] * diff[i] + arr[i][2]);
    }

    cout << rst << endl;

    return 0;
}
