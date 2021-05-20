// calc on the paper

#include <iostream>

using namespace std; 

int main() {
    int a, b, c, d, e, f;
    int x, y;
    cin >> a >> b >> c >> d >> e >> f;

    cout << (c * e - b * f) / (a * e - b * d) << " " << (c * d - f * a) / (b * d - e * a) << endl;

    return 0;
}
