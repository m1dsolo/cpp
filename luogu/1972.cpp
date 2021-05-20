#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 1e6 + 10;
int arr[N], order[N], rst[N], tree[N], last[N];
pair<int, int> qs[N];

int n;

void update(int i, int val) {
    for (; i <= n; i += i & -i)
	tree[i] += val;
}

int query(int i) {
    int rst = 0;
    for (; i; i -= i & -i)
	rst += tree[i];
    return rst;
}

int main() {
    scanf("%d", &n);
    int m;
    for (int i = 1; i <= n; i++)
	scanf("%d", &arr[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
	scanf("%d %d", &qs[i].first, &qs[i].second);

    iota(order, order + m, 0);
    sort(order, order + m, [&](int i, int j) {
	return qs[i].second < qs[j].second;
    });

    int index = 1;
    for (int j = 0; j < m; j++) {
	int i = order[j];
	int l = qs[i].first, r = qs[i].second;
	while (index <= r) {
	    if (last[arr[index]])
		update(last[arr[index]], -1);
	    update(last[arr[index]] = index, 1);
	    index++;
	}
	rst[i] = query(r) - query(l - 1);
    }

    for (int i = 0; i < m; i++)
	printf("%d\n", rst[i]);

    return 0;
}
