#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 2e3 + 10;	    // 注意开两倍！！！ n条边有可能有2n个点！！！

unordered_map<string, int> map1;
unordered_map<int, string> map2;
int arr[N], ps[N], wts[N];

int find(int a) {
    return a == ps[a] ? a : ps[a] = find(ps[a]);
}

void merge(int a, int b, int w) {
    int p1 = find(a), p2 = find(b);
    if (p1 != p2) {
	wts[p1] += wts[p2] + w;
	ps[p2] = p1;
    }
    else
	wts[p1] += w;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string name1, name2;
    int w, cnt = 0;
    for (int i = 0; i < n; i++) {
	cin >> name1 >> name2 >> w;
	if (map1.find(name1) == map1.end()) map1[name1] = ++cnt, map2[cnt] = name1, ps[cnt] = cnt;
	if (map1.find(name2) == map1.end()) map1[name2] = ++cnt, map2[cnt] = name2, ps[cnt] = cnt;
	merge(map1[name1], map1[name2], w);
	arr[map1[name1]] += w;
	arr[map1[name2]] += w;
    }

    unordered_map<int, vector<int>> map;
    for (int i = 1; i <= cnt; i++)
	map[find(i)].emplace_back(i);

    vector<pair<string, int>> rst;
    for (auto p : map) {
	if (wts[p.first] <= k || p.second.size() <= 2) continue;
	int max_val = 0, index;
	for (int a : p.second) {
	    if (arr[a] > max_val) {
		max_val = arr[a];
		index = a;
	    }
	}
	rst.push_back({map2[index], p.second.size()});
    }

    sort(rst.begin(), rst.end());
    cout << rst.size() << endl;
    for (auto p : rst)
	cout << p.first << " " << p.second << endl;

    return 0;
}
