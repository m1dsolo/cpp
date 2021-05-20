#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    int dp;
    cin >> dp;
    int rst = dp;
    int val;
    while (cin >> val) {
	dp = max(dp + val, val);	
	rst = max(rst, dp);
    }

    cout << rst << endl;

    return 0; 
}
