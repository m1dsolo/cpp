#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
const int N = 40;
int post[N], mid[N], lefts[N], rights[N];
vector<vector<int>> rst;

int dfs(int post_left, int post_right, int mid_left, int mid_right) {
    if (post_left > post_right || mid_left > mid_right) return 0;
    int root = post[post_right];
    int index = find(mid + mid_left, mid + mid_right + 1, root) - mid;
    int len = index - mid_left;
    lefts[root] = dfs(post_left, post_left + len - 1, mid_left, index - 1);
    rights[root] = dfs(post_left + len, post_right - 1, index + 1, mid_right);
    return root;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &mid[i]);
    for (int i = 0; i < n; i++)
	scanf("%d", &post[i]);

    int root = dfs(0, n - 1, 0, n - 1);
    queue<int> q;
    q.emplace(root);
    while(int size = q.size()) {
	vector<int> v;
	while (size--) {
	    int node = q.front(); q.pop();
	    v.emplace_back(node);
	    if (lefts[node]) q.emplace(lefts[node]);
	    if (rights[node]) q.emplace(rights[node]);
	}
	rst.emplace_back(v);
    }

    printf("R:");
    for (int i = 0; i < rst.size(); i++) {
	printf(" %d", rst[i].back());
    }
    printf("\n");
    printf("L:");
    for (int i = 0; i < rst.size(); i++) {
	printf(" %d", rst[i].front());
    }
    printf("\n");

    return 0;
}
