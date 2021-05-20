#include <iostream>
#include <numeric>

using namespace std;

const int N = 1010;

int n, m;
int parents[N];
pair<int, int> roads[N * N];

int find(int a) {
    return a == parents[a] ? a : parents[a] = find(parents[a]); 
}

void merge(int a, int b) {
    int p1 = find(a);
    int p2 = find(b); 
    if (p1 != p2)
	parents[p2] = p1;
}

int get_rst(int x) {
    iota(parents + 1, parents + 1 + n, 1);
    for (int i = 0; i < m; i++) {
	if (roads[i].first != x && roads[i].second != x)
	    merge(roads[i].first, roads[i].second);
    }
    int rst = -2;
    for (int i = 1; i <= n; i++) {
	if (i == parents[i])
	    rst++;
    }
    return rst;
}

int main() {
    int k, u;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
	scanf("%d %d", &roads[i].first, &roads[i].second);

    while (k--) {
	scanf("%d", &u);
	printf("%d\n", get_rst(u));
    }

    return 0;
}
