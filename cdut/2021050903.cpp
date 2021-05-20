#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char s[4];
    long long sum = 0;
    int a, size = 0, num = 1;
    double avg, med;
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int> q2;
    while (n--) {
	scanf("%s", &s);
	if (s[0] == 'a') {
	    scanf("%d", &a);
	    sum += a;
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
	    if (!size) {
		avg = 0;
		med = 0;
	    }
	    else {
		avg = (double)sum / size;
		med = size & 1 ? q1.top() : (q1.top() + q2.top()) / 2.0;
	    }
	    printf("Case #%d: %.2lf %.2lf\n", num++, avg, med);
	}
    }

    return 0;
}
