#include <iostream>
#include <queue>

using namespace std;

const int N = 2e5 + 10;

struct node {
    int d;
    int t;
} nodes[N];

struct task {
    int t;
    int id;
    int d;
    bool operator>(const task &t) const {
	return this->t > t.t;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
	scanf("%d", &nodes[i].d);

    priority_queue<task, vector<task>, greater<task>> q;
    int a, b, c, d;
    while (m--) {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	while (q.size() && q.top().t <= a) {
	    nodes[q.top().id].d += q.top().d;
	    q.pop();
	}
	if (d <= nodes[b].d) {
	    nodes[b].t = a + c;
	    printf("%d\n", nodes[b].d -= d);
	    q.push({nodes[b].t, b, d});
	}
	else
	    printf("-1\n");
    }

    return 0;
}
