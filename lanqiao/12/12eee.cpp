#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>

using namespace std;

typedef pair<int, int> P;
const int n = 2021;
vector<list<P>> graph(n + 1);
vector<int> dis(n + 1, INT_MAX);

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    int g = gcd(a, b);
    return a * b / g;
}

int main() {
    for (int i = 1; i <= n; i++) {
	for (int j = max(1, i - 21); j <= min(n, i + 21); j++) {
	    // cout << i << ' ' << j << endl;
	    graph[i].push_back({j, lcm(i, j)});
	}
    }

    vector<int> dis(n + 1, INT_MAX);
    dis[1] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, 1});
    while (int size = q.size()) {
	while (size--) {
	    int begin = q.top().second; q.pop();
	    for (P p : graph[begin]) {
		int end = p.first, val = p.second;
		if (dis[begin] + val < dis[end]) {
		    dis[end] = dis[begin] + val;
		    q.push({dis[end], end});
		}
	    }
	}
    }
    cout << dis[n] << endl;

    return 0;
}
