#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

bool visited[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int rst = 0, cnt = 0;
    queue<int> q;
    q.emplace(0);
    visited[0] = true;
    bool finish = false;
    while (int size = q.size()) {
	while (size--) {
	    int u = q.front(); q.pop();
	    if (++cnt == n) {
		finish = true;
		break;
	    }
	    int arr[2] {(u + 1) % n, (u + k) % n};
	    for (int a : arr) {
		if (!visited[a]) {
		    visited[a] = true;
		    q.emplace(a);
		}
	    }
	}
	if (finish) break;
	rst++;
    }

    printf("%d\n", rst);

    return 0;
}
