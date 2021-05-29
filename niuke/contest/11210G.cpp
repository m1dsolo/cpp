// 前缀和数字出现最多的次数
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e4 + 10;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	int n, a;
	scanf("%d", &n);
	unordered_map<int, int> map;
	int sum = 0, rst = 0;
	for (int i = 1; i <= n; i++) {
	    scanf("%d", &a);
	    map[sum += a]++;
	}
	for (auto p : map)
	    rst = max(rst, p.second);
	printf("%d\n", rst);
    }

    return 0;
}
