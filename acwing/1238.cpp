#include <iostream>
#include <algorithm>

using namespace std;
using P = pair<int, int>;

const int N = 1e5 + 10;

P arr[N];
int cnt[N];
bool rst[N];

int main() {
    int n, d, k;
    scanf("%d %d %d", &n, &d, &k);
    for (int i = 0; i < n; i++)
	scanf("%d %d", &arr[i].first, &arr[i].second);
    sort(arr, arr + n);

    int l = 0, r = 0;
    while (r < n) {
	cnt[arr[r].second]++;
	while (arr[r].first - arr[l].first >= d)
	    cnt[arr[l++].second]--;
	if (cnt[arr[r].second] >= k)
	    rst[arr[r].second] = true;
	r++;
    }

    for (int i = 1; i <= 1e5; i++)
	if (rst[i]) printf("%d\n", i);

    return 0;
}
