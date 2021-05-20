#include <iostream>
#include <algorithm>

using namespace std;
using P = pair<double, double>;

P arr[1010];


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
	scanf("%lf", &arr[i].first);
    for (int i = 0; i < n; i++)
	scanf("%lf", &arr[i].second);

    sort(arr, arr + n, [](P &p1, P &p2) {
	return p1.second / p1.first > p2.second / p2.first;
    });

    double rst = 0;
    for (int i = 0; i < n; i++) {
	double stock = arr[i].first, val = arr[i].second;
	if (stock >= m) {
	    rst += val * m / stock;
	    break;
	}
	else {
	    rst += val;
	    m -= stock;
	}
    }
    printf("%.2lf\n", rst);

    return 0;
}
