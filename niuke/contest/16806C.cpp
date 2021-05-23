// TLE
#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 110;

int n;
pair<int, int> arr[N];
unordered_set<int> sets[N];

void dfs(int index) {
    if (index == n - 1) {
	for (int i = arr[n - 1].first; i <= arr[n - 1].second; i++)
	    sets[n - 1].insert(i * i);
    }
    else {
	for (int i = arr[index].first; i <= arr[index].second; i++) {
	    if (!sets[index + 1].size())
		dfs(index + 1);
	    for (int a : sets[index + 1])
		sets[index].insert(a + i * i);
	}
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d %d", &arr[i].first, &arr[i].second);

    dfs(0);

    printf("%d\n", sets[0].size());

    return 0;
}
