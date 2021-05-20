#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>

using namespace std;

#define isdigit(x) ((x) >= '0' && (x) <= '9')

inline int read() {
    int rst = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) rst = (rst << 1) + (rst << 3) + c - 48, c = getchar();
    return rst;
}

int main() {
    map<int, vector<int>> map;
    unordered_map<int, int> win;
    int valid = 0;
    int n = read(), m = read(), a, b;
    for (int i = 1; i <= m; i++) {
	a = read();
	while (a--) {
	    b = read();
	    map[b].emplace_back(i);
	}
    }

    auto left = map.begin(), right = map.begin();
    int rst = INT_MAX;
    while (right != map.end()) {
	for (int a : right->second) {
	    if (!win[a]++)
		valid++;
	}
	while (valid >= m) {
	    rst = min(rst, right->first - left->first);
	    for (int a : left->second) {
		if (!--win[a])
		    valid--;
	    }
	    left++;
	}
	right++;
    }

    printf("%d\n", rst);

    return 0;
}
