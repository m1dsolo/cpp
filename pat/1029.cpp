#include <iostream>

using namespace std;

const int N = 2e5 + 10;
int arr1[N], arr2[N];

int main() {
    int m, n;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
	scanf("%d", &arr1[i]);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr2[i]);
    int cnt = (n + m + 1) / 2, p1 = 0, p2 = 0, rst;
    while (p1 < m && p2 < n) {
	rst = arr1[p1] < arr2[p2] ? arr1[p1++] : arr2[p2++];
	if (!--cnt) break;
    }
    if (cnt)
	rst = p1 < m ? arr1[p1 + cnt - 1] : arr2[p2 + cnt - 1];

    printf("%d\n", rst);

    return 0;
}
