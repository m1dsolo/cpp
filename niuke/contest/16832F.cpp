#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

const int N = 1e6 + 10;

pair<int, bool> arr[N];
int arr1[N], arr2[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	int n, m;
	scanf("%d %d", &n, &m);
	int max_i = n * m;
	for (int i = 0; i < max_i; i++)
	    scanf("%d", &arr[i].first);
	for (int i = 0; i < max_i; i++)
	    scanf("%d", &arr[i].second);

	memset(arr1, -1, sizeof(int) * n);
	memset(arr2, -1, sizeof(int) * n);
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
		if (arr[i * m + j].second)
		    arr2[i] = max(arr2[i], arr[i * m + j].first);
		else
		    arr1[i] = max(arr1[i], arr[i * m + j].first);
	    }
	}

	bool finish = arr1[0] == -1 && arr1[n - 1] == -1;

	for (int i = 1; i < n; i++) {
	    if (finish || (arr1[i - 1] == -1 && arr1[i] == -1)) {
		finish = true;
		break;
	    }
	}

	for (int i = 0; i < n; i++) {
	    if (finish || (arr1[i] == -1 && arr2[i] == -1)) {
		finish = true;
		break;
	    }
	    arr1[i] = max(arr1[i], 0);
	    arr2[i] = max(arr2[i], 0);
	}
	
	if (!finish) {
	    // 开始拿红
	    ll dp1 = arr1[0], dp2 = max(arr1[0], arr2[0]);
	    for (int i = 1; i < n - 1; i++) {
		dp2 += arr1[i];
		ll tmp = dp2;
		dp2 = max(dp2, dp1 + max(arr1[i], arr2[i]));
		dp1 = tmp;
		//ll t1 = dp1, t2 = dp2;
		//dp1 = max(t1 + arr1[i], t2 + arr1[i]);
		//dp2 = t1 + arr2[i];
	    }

	    ll rst = dp2 + arr1[n - 1];
	    // 开始不拿红
	    dp1 = arr1[0], dp2 = arr1[0];
	    for (int i = 1; i < n; i++) {
		dp2 += arr1[i];
		ll tmp = dp2;
		dp2 = max(dp2, dp1 + max(arr1[i], arr2[i]));
		dp1 = tmp;
		//ll t1 = dp1, t2 = dp2;
		//dp1 = max(t1 + arr1[i], t2 + arr1[i]);
		//dp2 = t1 + arr2[i];
	    }

	    printf("%lld\n", max(rst, dp2));
	}
	else
	    printf("-1\n");
    }

    return 0;
}
