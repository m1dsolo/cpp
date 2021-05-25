#include <iostream>
#include <climits>
#include <set>

using namespace std;

multiset<int> s;

int main() {
    int n, a;
    scanf("%d", &n);
    scanf("%d", &a);
    int rst = a;
    s.insert(INT_MAX), s.insert(INT_MIN), s.insert(a);
    for (int i = 1; i < n; i++) {
	scanf("%d", &a);
	auto it = s.insert(a);
	int tmp = INT_MAX;
	if (*--it != INT_MIN)
	    tmp = min(tmp, abs(*it - a));
	it++, it++;
	if (*it != INT_MAX)
	    tmp = min(tmp, abs(*it - a));
	rst += tmp;
    }

    printf("%d\n", rst);

    return 0;
}
