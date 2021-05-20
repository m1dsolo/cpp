// 分块，TLE
#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e5 + 10;
int n, num, arr[N], st[N], ed[N], bel[N], mark[N];

void build() {
    num = sqrt(n);
    for (int i = 1; i <= num; i++) {
	st[i] = n / num * (i - 1) + 1;
	ed[i] = n / num * i;
    }
    for (int i = 1; i <= num; i++) {
	for (int j = st[i]; j <= ed[i]; j++)
	    bel[j] = i;
    }
}

void update(int l, int r, int val) {
    if (bel[l] == bel[r]) {
	for (int i = l; i <= r; i++)
	    arr[i] += val;
    }
    else {
	for (int i = l; i <= ed[bel[l]]; i++)
	    arr[i] += val;
	for (int i = st[bel[r]]; i <= r; i++)
	    arr[i] += val;
	for (int i = bel[l] + 1; i < bel[r]; i++)
	    mark[i] += val;
    }
}

long long query(int l, int r) {
    long long rst = 0;
    if (bel[l] == bel[r]) {
	for (int i = l; i <= r; i++)
	    rst += arr[i];
    }
    else {
	for (int i = l; i <= ed[bel[l]]; i++)
	    rst += arr[i];
	for (int i = st[bel[r]]; i <= r; i++)
	    rst += arr[i];
	for (int i = bel[l] + 1; i < bel[r]; i++)
	    rst += mark[i] * (ed[i] - st[i] + 1);
    }
    return rst;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);

    int a, l, r, k;
    while (m--) {
	scanf("%d %d %d", &a, &l, &r);
	if (a == 1) {
	    scanf("%d", &k);
	    update(l, r, k);
	}
	else {
	    printf("%lld\n", query(l, r));
	}
    }

    return 0;
}
