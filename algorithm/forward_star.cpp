// 链式前向星
/*
1 2
2 3
3 4
1 3
4 1
1 5
4 5
*/

#include <iostream>

using namespace std;

const int n = 5;
struct edge {
    int next;
    int to;
    int w;
} edges[100];

int head[n + 1];

int cnt = 1;
void add_edge(int u, int v, int w) {
    edges[cnt].to = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}

int main() {
    int u, v;
    while (scanf("%d %d", &u, &v) != EOF) {
	add_edge(u, v, 0);
    }

    for (int i = 1; i <= n; i++) {
	for (int j = head[i]; j; j = edges[j].next) {
	    cout << i << " " << edges[j].to << " " << edges[j].w << endl;
	}
    }

    return 0;
}
