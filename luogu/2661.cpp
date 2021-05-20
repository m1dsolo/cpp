#include <iostream>
#include <numeric>
#include <climits>

using namespace std;

const int N = 2e5 + 10;

int parents[N], size[N];

int find(int a, int &cnt) {
    cnt++;
    return a == parents[a] ? a : find(parents[a], cnt);
}

int main() {
    int n, a, rst = INT_MAX;
    scanf("%d", &n);
    iota(parents + 1, parents + 1 + n, 1);
    fill(size + 1, size + 1 + n, 1);
    for (int i = 1; i <= n; i++) {
	int cnt = 0;
	scanf("%d", &a);
	if (find(a, cnt) == i)	    // 成环了更新结果，但是不给连成环(防止find无限循环)
	    rst = min(rst, cnt);
	else
	    parents[i] = a;
    }

    cout << rst << endl;

    return 0;
}
