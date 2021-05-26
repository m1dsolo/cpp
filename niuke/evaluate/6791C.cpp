#include <iostream>
#include <vector>

using namespace std;

vector<int> v1, v2;

const int N = 40;
int n, rst = 0;
bool adj[N][N];

void dfs(int index) {
    if (index == n) rst++;
    else {
	bool flag = true;
	for (int a : v1) {
	    if (adj[a][index]) {
		flag = false;
		break;
	    }
	}
	if (flag) {
	    v1.emplace_back(index);
	    dfs(index + 1);
	    v1.pop_back();
	}

	flag = true;
	for (int a : v2) {
	    if (adj[a][index]) {
		flag = false;
		break;
	    }
	}
	if (flag) {
	    v2.emplace_back(index);
	    dfs(index + 1);
	    v2.pop_back();
	}
    }
}

int main() {
    scanf("%d", &n);
    int m, a;
    for (int i = 0; i < n; i++) {
	scanf("%d", &m);
	for (int j = 0; j < m; j++) {
	    scanf("%d", &a);
	    adj[i][a] = true;
	    adj[a][i] = true;
	}
    }

    dfs(0);

    printf("%d\n", rst ? rst : -1);

    return 0;
}
