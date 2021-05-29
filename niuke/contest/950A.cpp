#include <iostream>
#include <algorithm>

using namespace std;
using P = pair<int, int>;

const int N = 1e3 + 10;
P arr[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d %d", &arr[i].first, &arr[i].second);

    sort(arr, arr + n, [](const P &p1, const P &p2) {
	return p1.second < p2.second;
    });

    int end = arr[0].second, rst = 1;
    for (int i = 1; i < n; i++) {
	if (arr[i].first >= end) {
	    end = arr[i].second;
	    rst++;
	}
    }

    printf("%d\n", rst);

    return 0;
}
