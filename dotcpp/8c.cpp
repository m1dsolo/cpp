#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    vector<vector<double>> vals(30, vector<double>(30, 0));
    double tmp;
    for (int i = 0; i < 29; i++) {
	for (int j = 0; j <= i; j++) {
	    cin >> tmp;
	    vals[i][j] += tmp;
	    vals[i + 1][j] += vals[i][j] / 2;
	    vals[i + 1][j + 1] += vals[i][j] / 2;
	}
    }
    double min_val = 1e9;
    double max_val = 0;
    for (int i = 0; i < 30; i++) {
	min_val = min(min_val, vals[29][i]);
	max_val = max(max_val, vals[29][i]);
    }

    tmp = 2086458231;
    printf("%lf\n", tmp * max_val / min_val);

    return 0;
}
