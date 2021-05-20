#include <iostream>
#include <vector>

using namespace std;

int n, x;
int arr[510][510];

bool helper(vector<int> &l, vector<int> &w) {
    if (!l.size()) return true;
    if (!w.size()) return false;
    vector<int> ll, ww;
    for (int a : l) {	    // 如果a能打败所有b，那么a应该在ll内(淘汰掉强者)
	bool flag = true;
	for (int b : w) {
	    if (arr[b][a]) {
		flag = false;
		break;
	    }
	}
	if (flag)
	    ll.emplace_back(a);
	else
	    ww.emplace_back(a);
    }

    return helper(ll, ww);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++) {
		scanf("%d", &arr[i][j]);
	    }
	}
	scanf("%d", &x);

	vector<int> l(n - 1), w({x});
	int cnt = 1;
	for (int &a : l) {
	    if (cnt == x)
		cnt++;
	    a = cnt++;
	}

	printf("%s\n", helper(l, w) ? "Yes" : "No");
    }

    return 0;
}
