#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct stick {
    int l, w;
    bool operator<(const stick &s) const {
	return w < s.w;
    }
    bool operator>(const stick &s) const {
	return w > s.w;
    }
} sticks[5001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
	scanf("%d %d", &sticks[i].l, &sticks[i].w);

    sort(sticks, sticks + n, [](stick &s1, stick &s2) {
	return s1.l == s2.l ? s1.w > s2.w : s1.l > s2.l;
    });

    vector<stick> tail;
    tail.emplace_back(sticks[0]);
    for (int i = 1; i < n; i++) {
	if (sticks[i] > tail.back())
	    tail.emplace_back(sticks[i]);
	else
	    *lower_bound(tail.begin(), tail.end(), sticks[i]) = sticks[i];
    }

    cout << tail.size() << endl;

    return 0;
}
