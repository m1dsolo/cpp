// CF1110B
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int arr[N];

// 如果k == n，那么rst == k，而没少一段胶带，贪心地增加最短间距
int main() {
    int n, m, k, a, b;
    scanf("%d %d %d", &n, &m, &k); 
    scanf("%d", &a);
    for (int i = 0; i < n - 1; i++) {
	scanf("%d", &b);
	arr[i] = b - a;
	a = b;
    }

    int rst = 0;
    sort(arr, arr + n - 1);
    for (int i = 0; i < n - k; i++)
	rst += arr[i];

    printf("%d\n", rst + k);

    return 0;
}
