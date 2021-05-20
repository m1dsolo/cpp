#include <iostream>
#include <cmath>

using namespace std;

int n, k;
int rst = 0;
void dfs(int len, int num) {
    if (len == n) {
	rst += pow(k - 1, num);
	return;
    }
    else if (len == n + 1) { 
	rst += pow(k - 1, num - 1);
	return;
    }
    
    dfs(len + 1, num + 1);
    dfs(len + 2, num + 1);
}

int main() {
    cin >> n >> k;
    dfs(1, 1);
    cout << rst << endl;

    return 0;
}
