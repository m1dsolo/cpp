#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 510;

struct node {
    int t;
    int v;
} arr[N];

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i].t);
    for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i].v);
	m -= arr[i].v;
    }
    sort(arr, arr + n, [](const node &n1, const node &n2) {
	return n1.t < n2.t;
    });

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {	// 要使最后堆内的和最大
	if (arr[i].t > q.size())
	    q.emplace(arr[i].v);
	else if (arr[i].v > q.top()) {
	    q.pop();
	    q.emplace(arr[i].v);
	}
    }
    while (q.size()) {
	m += q.top(); q.pop();
    }

    printf("%d\n", m);

    return 0;
}
