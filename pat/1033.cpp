#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;
pair<double, double> arr[N];	// {loc, cost}

int main() {
    double c, d, v;
    int n; 
    scanf("%lf %lf %lf %d", &c, &d, &v, &n);
    for (int i = 0; i < n; i++)
	scanf("%lf %lf", &arr[i].second, &arr[i].first);
    arr[n] = {d, 1e10};
    sort(arr, arr + n + 1);

    bool flag = false;
    int src = 0;
    double rst = 0;
    if (!arr[0].first) {
	while (1) {
	    if (arr[src + 1].first > arr[src].first + c * v) break;
	    int dst = src + 1;
	    arr[n].second = arr[src].second;
	    while (dst <= n && arr[dst].first <= arr[src].first + c * v) {
		if (arr[dst++].second <= arr[src].second)
		    break;
	    }
	    dst--;
	    double step = arr[dst].first - arr[src].first;
	    rst += arr[src].second * step;
	    if (arr[dst].second > arr[src].second)
		rst -= (arr[dst].second - arr[src].second) * (c * v - step);
	    if ((src = dst) == n) {
		flag = true;
		break;
	    }
	}
    }

    if (flag)
	printf("%.2lf\n", rst / v);
    else
	printf("The maximum travel distance = %.2lf\n", arr[src].first + c * v);

    return 0;
}
