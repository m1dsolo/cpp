// 写的太丑了，以后看有没有简洁的写法把
#include <iostream>

using namespace std;

struct node {
    int val;
    int next;
} nodes[100010];

bool used[10010];

int main() {
    int ptr, n, a, b, c;
    scanf("%d %d", &ptr, &n);
    for (int i = 0; i < n; i++) {
	scanf("%d %d %d", &a, &b, &c);
	nodes[a].val = b;
	nodes[a].next = c;
    }

    int ptr0 = 100005, ptr1 = 100006;
    nodes[ptr0].next = -1, nodes[ptr1].next = -1;
    while (ptr != -1) {
	int val = abs(nodes[ptr].val);
	int next = nodes[ptr].next;
	if (!used[val]) {
	    used[val] = true;
	    nodes[ptr0].next = ptr;
	    ptr0 = ptr;
	}
	else {
	    nodes[ptr1].next = ptr;
	    ptr1 = ptr;
	}
	nodes[ptr].next = -1;
	ptr = next;
    }

    ptr0 = nodes[100005].next;
    while (ptr0 != -1 && nodes[ptr0].next != -1) {
	printf("%05d %d %05d\n", ptr0, nodes[ptr0].val, nodes[ptr0].next);
	ptr0 = nodes[ptr0].next;
    }
    if (ptr0 != -1) printf("%05d %d %d\n", ptr0, nodes[ptr0].val, -1);

    ptr1 = nodes[100006].next;
    while (ptr1 != -1 && nodes[ptr1].next != -1) {
	printf("%05d %d %05d\n", ptr1, nodes[ptr1].val, nodes[ptr1].next);
	ptr1 = nodes[ptr1].next;
    }
    if (ptr1 != -1) printf("%05d %d %d\n", ptr1, nodes[ptr1].val, -1);

    return 0;
}
