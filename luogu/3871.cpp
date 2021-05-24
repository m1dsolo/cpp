#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int size = 0;
priority_queue<int, vector<int>, greater<int>> q1;
priority_queue<int> q2;

void push(int a) {
    if (size & 1) {
	q1.emplace(a);
	q2.emplace(q1.top());
	q1.pop();
    }
    else {
	q2.emplace(a);
	q1.emplace(q2.top());
	q2.pop();
    }
    size++;
}

int get() {
    return (size & 1) ? q1.top() : q2.top();
}

int main() {
    int n, m, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d", &a);
	push(a);
    }

    char s[4];
    scanf("%d", &m);
    while (m--) {
	scanf("%s", s);
	if (!strcmp(s, "add")) {
	    scanf("%d", &a);
	    push(a);
	}
	else
	    printf("%d\n", get());
    }

    return 0;
}
