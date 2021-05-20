// 多边形面积公式
// S = abs($$\sum_{i = 0}^n(x_i * y_i+1 - x_i+1 * y_i))

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<pair<int, int>> points{{3, 4}, {5, 11}, {12, 8}, {9, 5}, {5, 6}};
    int rst = 0, n = points.size();
    for (int i = 0; i < n - 1; i++) {
	rst += points[i].first * points[i + 1].second - points[i].second * points[i + 1].first;
    }
    rst += points[n - 1].first * points[0].second - points[n - 1].second * points[0].first;
    cout << abs(rst / 2) << endl;
    // rst = 30;

    return 0;
}
