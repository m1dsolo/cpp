// 双堆维护中位数
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    char s[4];
    int a, size = 0;
    priority_queue<int, vector<int>, greater<int>> q1;	// 小根堆维护较大的一半
    priority_queue<int> q2;	// 大根堆维护较小的一半
    while (n--) {
	scanf("%s", &s);
	if (s[0] == 'a') {
	    scanf("%d", &a);
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
	else {
	    double rst;
	    if (!size) rst = 0;
	    else if (size & 1) rst = q1.top();
	    else rst = (q1.top() + q2.top()) / 2.0;
	    printf("%.2lf\n", rst);
	}
    }

    return 0;
}
