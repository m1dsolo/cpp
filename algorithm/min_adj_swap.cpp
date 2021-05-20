#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

const int N = 1e6 + 10;

int n;
int tree[N];

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

int get_inverse_pair(const vector<int> &v) {
    int rst = 0;
    for (int i = 0; i < n; i++) {
	rst += i - query(v[i]);
	update(v[i]);	    // update在query后面是因为i从0开始迭代，而不是1
    }
    return rst;
}

//int min_adj_swap(vector<int> &v1, vector<int> &v2) {
    //vector<int> order1(n), order2(n), rank(n);
    //iota(order1.begin(), order1.end(), 0);
    //iota(order2.begin(), order2.end(), 0);
    //sort(order1.begin(), order1.end(), [&](int i, int j) {
	//return v1[i] < v1[j];
    //});
    //sort(order2.begin(), order2.end(), [&](int i, int j) {
	//return v2[i] < v2[j];
    //});

    //for (int i = 0; i < n; i++)
	//rank[order1[i]] = order2[i] + 1;

    //return get_inverse_pair(rank);
//}

// 处理重复
// O(nlogn)来自于求逆序对
int min_adj_swap(const vector<int> &v1, const vector<int> &v2) {
    int n = v1.size();
    unordered_map<int, pair<vector<int>, int>> map;
    for (int i = 0; i < n; i++)
	map[v1[i]].first.emplace_back(i + 1);

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
	auto p = &map[v2[i]];	// 注意!!
	v[i] = p->first[p->second++];
    }

    return get_inverse_pair(v);
}

int main() {
    vector<int> v1 {10, 50, 20, 30, 40}, v2 {50, 40, 20, 10, 30};
    n = v1.size();

    cout << min_adj_swap(v1, v2) << endl;

    return 0;
}
