#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int n;
vector<string> dp;

string dfs_s(int index) {
    stringstream rst;
    if (index == 1) 
	rst << dp[1] << "+" << n;
    else
	rst << "(" << dfs_s(index - 1) << ")" << dp[index] << "+" << n + 1 - index; 

    return rst.str();
}

int main() {
    cin >> n;

    dp = vector<string>(n + 1);
    stringstream ss;
    ss << "sin(1";
    for (int i = 1; i <= n; i++) {
	stringstream tmp;
	tmp << ss.str();
	for (int j = 0; j < i; j++) tmp << ')';
	dp[i] = tmp.str();
	
	ss << ((i % 2) ? '-' : '+') << "sin(" << i + 1;
    }

    cout << dfs_s(n) << endl;

    return 0;
}
