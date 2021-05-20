#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

inline int get_hash(int a, int b, int c) {
    return a * 40000 + b * 200 + c;
}

inline int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    vector<vector<vector<int>>> dp(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1)));
    unordered_map<int, int> map;
    int a, b, c, val;
    while (1) {
	scanf("%d %d %d %d", &a, &b, &c, &val);
	if (!a && !b && !c && !val) break;
	map[get_hash(a, b, c)] += val;
    }
    for (int i = 1; i <= x; i++) {
	for (int j = 1; j <= y; j++) {
	    for (int k = 1; k <= z; k++) {
		dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]) + map[get_hash(i, j, k)];
	    }
	}
    }
    cout << dp[x][y][z] << endl;

    return 0;
}
