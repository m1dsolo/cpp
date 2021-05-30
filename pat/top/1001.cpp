// 29分，测试点3错了
#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

const int N = 510;

int n, m, rst[N], ps[N];
struct edge {
    int u;
    int v;
    int w;
} es[(int)1e6];

int find(int a) {
    return a == ps[a] ? a : ps[a] = find(ps[a]);
}

void merge(int a, int b) {
    ps[find(b)] = find(a);
}

int kruskal(int a) {
    int cnt = 0;
    if (cnt == n - 2) return 0;
    iota(ps + 1, ps + 1 + n, 1);
    for (int i = 0; i < m; i++) {
	if (es[i].u == a || es[i].v == a) continue;
	if (find(es[i].u) != find(es[i].v)) {
	    merge(es[i].u, es[i].v);
	    rst[a] += es[i].w;
	    if (++cnt == n - 2)
		break;
	}
    }
    return rst[a];
}

int main() {
    int s;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
	scanf("%d %d %d %d", &es[i].u, &es[i].v, &es[i].w, &s);
	if (s) es[i].w = 0;
    }
    sort(es, es + m, [](const edge &e1, const edge &e2) {
	return e1.w < e2.w;
    });

    int max_val = 0;
    for (int i = 1; i <= n; i++)
	max_val = max(max_val, kruskal(i));

    if (max_val) {
	stringstream ss;
	for (int i = 1; i <= n; i++) {
	    if (rst[i] == max_val)
		ss << i << " ";
	}
	string s = ss.str();
	printf("%s\n", s.substr(0, s.length() - 1).c_str());
    }
    else
	printf("0\n");

    return 0;
}
