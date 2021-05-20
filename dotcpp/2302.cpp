#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> candys(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < k; j++) {
	    cin >> candys[i][j];
	}
    }



    return 0;
}
