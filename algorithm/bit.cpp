// 树状数组(binary indexed tree)
#include <iostream>
#include <vector>

using namespace std;

const int N = 100;
int tree[N], n;

// 1.单点修改，区间查询
void update(int i, int a) {
    for (; i <= n; i += i & -i)
	tree[i] += a;
}

int query(int i) {
    int rst = 0;
    for (; i; i -= i & -i)
	rst += tree[i];
    return rst;
}

// 2.区间修改，单点查询
void update(int l, int r, int a) {
    update(l, a), update(r + 1, -a);
}

int main() {
    vector<int> v{1, 5, 2, 4, 3};
    n = v.size();
    for (int i = 0; i < v.size(); i++)
	update(i + 1, i + 1, v[i]);

    update(2, 4, 2);

    for (int i = 1; i <= v.size(); i++) {
	cout << query(i) << endl;
    }

    return 0;
}
