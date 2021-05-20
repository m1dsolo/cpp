#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;

struct Q {
    int l;
    int r;
    int k;
    int id;
} qs[N];

struct A {
    int val;
    int id;
} arr[N];

int n, tree[N], rst[N];

void update(int i) {
    for (; i <= n; i += i & -i)
	tree[i]++;
}

int query(int i) {
    int rst = 0;
    for (; i; i -= i & -i)
	rst += tree[i];
    return rst;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    set<int> set;
    for (int i = 1; i <= n; i++) {
	scanf("%d", &arr[i].val);
	arr[i].id = i;
	set.insert(arr[i].val);
    }
    sort(arr + 1, arr + 1 + n, [](const A &a1, const A &a2) {
	return a1.val > a2.val;
    });

    for (int i = 0; i < m; i++) {
	scanf("%d %d %d", &qs[i].l, &qs[i].r, &qs[i].k);
	qs[i].id = i;
	set.insert(qs[i].k);
    }
    sort(qs, qs + m, [](const Q &q1, const Q &q2) {
	return q1.k > q2.k;
    });

    unordered_map<int, int> map;
    int cnt = 1;
    for (int a : set)
	map[a] = cnt++;

    int index = 1, val;
    for (int i = 0; i < m; i++) {
	while (index <= n && (val = arr[index].val) > qs[i].k) {
	    update(arr[index].id);
	    index++;
	}
	rst[qs[i].id] = query(qs[i].r) - query(qs[i].l - 1);
    }

    for (int i = 0; i < m; i++)
	printf("%d\n", rst[i]);

    return 0;
}
