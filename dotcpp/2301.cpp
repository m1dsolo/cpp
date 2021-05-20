#include <iostream>

using namespace std;

const int N = 1000001;
int fathers[N] = {0};
int find(int x) {
    return (fathers[x] == x) ? x : fathers[x] = find(fathers[x]);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int min_val = 1;
    for (int i = 0; i < N; i++)
	fathers[i] = i;
    for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
	arr[i] = find(arr[i]);
	printf("%d ", arr[i]);
	fathers[arr[i]] = arr[i] + 1;
    }
    printf("\n");

    return 0;
}
