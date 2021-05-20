#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct Edge {
    int start;
    int end;
    int len;
};

class UnionFind {
private:
    vector<int> parents, ranks, sizes, lens;
public:
    UnionFind(int n) : parents(n), ranks(n), sizes(n, 1), lens(n) {
	for (int i = 0; i < n; i++) {
	    parents[i] = i;
	}
    }

    int find(int a) {
	return (a == parents[a]) ? a : parents[a] = find(parents[a]);
    }

    int merge(int a, int b, int len) {
	int p1 = find(a);
	int p2 = find(b);
	if (p1 != p2) {
	    if (ranks[p1] < ranks[p2])
		swap(p1, p2);
	    parents[p2] = p1;
	    if (ranks[p1] == ranks[p2]) ranks[p1]++;
	    sizes[p1] += sizes[p2];
	    lens[p1] += lens[p2] + len;
	    if (sizes[p1] == n) return lens[p1];
	}
	return 0;
    }
};

int main() {
    vector<pair<int, int>> points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    n = points.size();
    vector<Edge> edges;
    for (int i = 0; i < n - 1; i++) {
	for (int j = i + 1; j < n; j++) {
	    edges.push_back({i, j, abs(points[j].first - points[i].first) + abs(points[j].second - points[i].second)});
	}
    }
    sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2)->bool{
	return e1.len < e2.len;
    });

    UnionFind uf(n);

    for (Edge &edge : edges) {
	if (int rst = uf.merge(edge.start, edge.end, edge.len)) {
	    cout << rst << endl;
	    break;
	}
    }

    return 0;
}
