#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;

int n;
//vector<int> discretize(const vector<int> &v) {
    //vector<int> order(n), rst(n);
    //iota(order.begin(), order.end(), 0);
    //sort(order.begin(), order.end(), [&](int i, int j) {
	//return v[i] < v[j];
    //});

    ////for (int i = 0; i < n; i++)
	////rst[order[i]] = i;
	
    //rst[order[0]] = 0;
    //for (int i = 1; i < n; i++)
	//rst[order[i]] = rst[order[i - 1]] + (v[order[i - 1]] != v[order[i]]);

    //return rst;
//}

vector<int> discretize(const vector<int> &v) {
    vector<pair<int, int>> vv(n);
    for (int i = 0; i < n; i++) {
	vv[i] = {v[i], i};
    }
    sort(vv.begin(), vv.end());

    vector<int> rst(n);
    //for (int i = 0; i < n; i++)
	//rst[vv[i].second] = i;
    
    rst[vv[0].second] = 0;
    for (int i = 1; i < n; i++)
	rst[vv[i].second] = rst[vv[i - 1].second] + (vv[i - 1].first != vv[i].first);
    return rst;
}

//void discretize(const vector<int> &v) {
    //set<int> set;	// 去重了
    //for (int a : v)
	//set.insert(a);

    //unordered_map<int, int> map;
    //int i = 0;
    //for (int a : set) {
	//map[a] = i++;
    //}
//}

int main() {
    vector<int> v{10, 60, 20, 40, 50, 30, 20, 20};
    n = v.size();

    vector<int> rst = discretize(v);
    for (int a : rst)
	cout << a << " ";
    cout << endl;

    return 0;
}
