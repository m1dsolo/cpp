#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 15010;

struct q {
    double l;
    double r;
} qs[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	int n, l, w, x, r, cnt = 0;
	scanf("%d %d %d", &n, &l, &w);
	for (int i = 0; i < n; i++) {
	    scanf("%d %d", &x, &r);
	    double tmp = sqrt((double)r * r - (double)w * w / 4);
	    qs[i].l = (r <= w / 2) ? 2e9 : x - tmp;	    // 注意特例！！！
	    qs[i].r = (r <= w / 2) ? 2e9 : x + tmp;
	}
	sort(qs, qs + n, [](const q &q1, const q &q2) {
	    return q1.l < q2.l;
	});
	double begin = 0;
	int rst = 0;
	while (begin < l) {
	    double max_val = 0;
	    for (int i = 0; i < n && qs[i].l <= begin; i++)
		max_val = max(max_val, qs[i].r);
	    if (max_val <= begin) {
		rst = -1;
		break;
	    }
	    begin = max_val;
	    rst++;
	}
	printf("%d\n", rst);
    }

    return 0;
}
