#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

struct cmp {
    bool operator()(const P &p1, const P &p2) const {
	return (double)p1.second / p1.first < (double)p2.second / p2.first;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    priority_queue<P, vector<P>, cmp> q;

    int t, d;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
	scanf("%d %d", &t, &d);
	q.push({t, d});
	sum += d;
    }	
    //sort(arr, arr + n, [](const P &p1, const P &p2) {
	//return (double)p1.second / p1.first > (double)p2.second / p2.first;
    //});

    long long rst = 0;
    for (int i = 0; i < n; i++) {
	t = q.top().first, d = q.top().second; q.pop();
	sum -= d;
	rst += sum * t * 2;
    }

    cout << rst << endl;

    return 0;
}
