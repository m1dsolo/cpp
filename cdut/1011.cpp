#include <iostream>

using namespace std;

const int N = 5e4 + 10;
int arr[N] = {1};
long long sum[N];
int main() {
    char c;
    int n = 0;
    for (int i = 1; i < N; i++) {
	scanf("%c", &c);
	if (!isdigit(c)) break;
	arr[n += (c - '0')]++;
    }

    for (int i = 0; i <= n; i++) {
	for (int j = 0; j < i; j++)
	    sum[i - j + 1] += arr[i] * arr[j];
	sum[1] += arr[i] * (arr[i] - 1) / 2;
    }

    for (int i = 1; i <= n + 1; i++)
	sum[i] += sum[i - 1];

    int m, l, r;
    scanf("%d", &m);
    while (m--) {
	scanf("%d %d", &l, &r);
	printf("%lld\n", sum[r + 1] - sum[l]);
    }

    return 0;
}
