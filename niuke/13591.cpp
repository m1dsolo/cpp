#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int arr[N];

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
	for (int i = 0; i < n; i++)
	    scanf("%d", &arr[i]);
	sort(arr, arr + n);

	int rst = 0;
	for (int i = 0; i < n - 1; i++) {
	    if (arr[i + 1] - arr[i] < m) {
		rst++;
		i++;
	    }
	}
	printf("%d\n", rst);
    }

    return 0;
}
