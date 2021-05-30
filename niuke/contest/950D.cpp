// johnson法则(看不懂)https://blog.nowcoder.net/n/a250684e7dfc4122aa84c0c41489f2bd?from=nowcoder_improve
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

const int N = 1e3 + 10;

struct node {
    int a;
    int b;
    int id;
    void operator=(int a){id = a;}
} arr[N];

int main() {
    int n;
    scanf("%d", &n);
    iota(arr, arr + n, 1);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i].a);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i].b);
    sort(arr, arr + n, [](const node &n1, const node &n2) {
	return min(n1.a, n2.b) == min(n1.b, n2.a) ? n1.a < n2.a : min(n1.a, n2.b) < min(n1.b, n2.a);
    });

    ll x = 0, y = 0;
    for (int i = 0; i < n; i++) {
	x += arr[i].a;
	y = max(x, y) + arr[i].b;
    }

    printf("%d\n", y);
    for (int i = 0; i < n - 1; i++)
	printf("%d ", arr[i].id);
    printf("%d\n", arr[n - 1].id);

    return 0;
}
