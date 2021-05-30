#include <iostream>

using namespace std;

const int N = 1e5 + 10;

struct node {
    int next = -1;
    bool flag = false;
} nodes[N];

int main() {
    int root1, root2, n;
    scanf("%d %d %d", &root1, &root2, &n);
    char s[2];
    int addr; 
    while (n--) {
	scanf("%d", &addr);
	scanf("%s %d", &s, &nodes[addr].next);
    }

    while (root1 != -1) {
	nodes[root1].flag = true;
	root1 = nodes[root1].next;
    }

    int rst = -1;
    while (root2 != -1) {
	if (nodes[root2].flag) {
	    rst = root2;
	    break;
	}
	root2 = nodes[root2].next;
    }

    if (rst == -1)
	printf("-1\n");
    else
	printf("%05d\n", rst);

    return 0;
}
