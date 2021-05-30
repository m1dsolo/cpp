#include <iostream>
#include <numeric>

using namespace std;

const int N = 2e5 + 10;

int ps[N];

int find(int a, int &cnt) {
    cnt++;
    return a == ps[a] ? a : find(ps[a], cnt);	// 别路径压缩了
}

int main() {
    int n, a, rst = 2e9;
    scanf("%d", &n);
    iota(ps + 1, ps + 1 + n, 1);
    for (int i = 1; i <= n; i++) {
	scanf("%d", &a);
	int cnt = 0;
	if (find(a, cnt) == i)	   // 成环
	    rst = min(rst, cnt);
	else
	    ps[i] = a;	    // 别指反了，i要指向a
    }

    printf("%d\n", rst);

    return 0;
}
