#include <iostream>
#include <list>
#include <queue>
#include <unordered_set>
#include <cstring>

using namespace std;

const int N = 30;

int n;
list<int> adj[N];
int ind_tmp[N], ind[N], path[N], len;
unordered_set<int> set;

int topo() {
    queue<int> q;
    for (int i = 0; i < n; i++) {
	if (!ind[i] && set.count(i))
	    q.emplace(i);
    }

    int cnt = 0, level = 0;
    while (int size = q.size()) {
	while (size--) {
	    int u = q.front(); q.pop(); cnt++;
	    path[len++] = u;
	    for (int v : adj[u]) {
		if (!--ind[v]) {
		    q.emplace(v);
		}
	    }
	}
	level++;
    }

    if (level == n)
	return 1;
    if (cnt < set.size())
	return -1;
    return 0;
}

int main() {
    int m, rst;
    scanf("%d %d", &n, &m);
    char s[5];
    bool finish = false;
    for (int i = 1; i <= m; i++) {
	scanf("%s", s);	
	adj[s[0] - 'A'].emplace_back(s[2] - 'A');
	ind_tmp[s[2] - 'A']++;
	memcpy(ind, ind_tmp, sizeof(ind));
	set.insert(s[0] - 'A');
	set.insert(s[2] - 'A');
	len = 0;
	if ((rst = topo()) == 1) {
	    printf("Sorted sequence determined after %d relations: ", i);
	    for (int i = 0; i < len; i++)
		printf("%c", path[i] + 'A');
	    printf(".\n");
	    finish = true;
	    break;
	}
	else if (rst == -1) {
	    printf("Inconsistency found after %d relations.\n", i);
	    finish = true;
	    break;
	}
    }
    if (!finish)
	printf("Sorted sequence cannot be determined.\n");

    return 0;
}
