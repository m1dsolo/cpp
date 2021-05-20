// dont know very well
// not AC

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    vector<vector<unsigned long long>> dp(N + 1, vector<unsigned long long>(K + 1, 1));
    for (int j = 1; j <= K; j++) {
	for (int i = 1; i <= N; i++) {
	    for (int k = j; k < i; k++)
		dp[i][j] = max(dp[i][j], dp[k][j - 1] * stoull(s.substr(i + 1, s.length() - (i + 1))));
	}
    }
    
    cout << dp[N][K] << endl;

    return 0;
}
