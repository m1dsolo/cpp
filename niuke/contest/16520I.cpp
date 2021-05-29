// 看题解才会的
// O(4000 ** 2)，不是O(n ** 2)是因为点没遍历完，桶会先满
#include <iostream>

using namespace std;
using P = pair<int, int>;

const int N = 1e5 + 10;

int x[N], y[N];
P ps[4010][4010];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf("%d %d", &x[i], &y[i]);
	for (int j = 1; j < i; j++) {
	    int xx = x[i] + x[j] + 2000, yy = y[i] + y[j] + 2000;   // 中点
	    if (i == ps[xx][yy].first || i == ps[xx][yy].second || j == ps[xx][yy].first || j == ps[xx][yy].second) continue;	// 保证4个点互不相同
	    if (ps[xx][yy].first) {
		printf("YES\n%d %d %d %d\n", i, j, ps[xx][yy].first, ps[xx][yy].second);
		return 0;
	    }
	    ps[xx][yy] = {i, j};
	}
    }
    printf("NO\n");

    return 0;
}
