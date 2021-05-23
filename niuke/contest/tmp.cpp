#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int N = 110;

int n;
pair<int, int> arr[N];
unordered_map<int, unordered_set<int>> map;

void dfs(int index) {
    cout << index << endl;
    if (index == n - 1) {
	for (int i = arr[n - 1].first; i <= arr[n - 1].second; i++)
	    map[n - 1].insert(i);
    }
    else {
	for (int i = arr[index].first; i <= arr[index].second; i++) {
	    if (!map[index + 1].size())
		dfs(index + 1);
	    for (int a : map[index + 1])
		map[index].insert(a + i * i);
	}
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d %d", &arr[i].first, &arr[i].second);

    dfs(0);

    printf("%d\n", map[0].size());

    return 0;
}
