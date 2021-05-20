#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    int g = gcd(a, b);
    return a * b / g;
}

int main() {
    int n = 2021;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++) {
	for (int j = max(1, i - 21); j <= min(n, i + 21); j++) {
	    graph[i][j] = lcm(i, j);
	}
    }

    for (int k = 1; k <= n; k++) {
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++) {
		if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
		    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
	    }
	}
    }

    cout << graph[1][2021] << endl;

    return 0;
}
