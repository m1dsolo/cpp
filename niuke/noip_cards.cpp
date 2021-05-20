#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct card {
    int a, b, c;
    bool operator<(const card &c) {
	if (a != c.a) return a < c.a;
	if (b != c.b) return b < c.b;
	return this->c < c.c;
    }
};

bool helper(const card &c1, const card &c2) {
    return c1.b <= c2.b && c1.c <= c2.c;
}

int main() {
    int n;
    cin >> n;
    vector<card> cards(n);
    int a, b, c;
    for (int i = 0; i < n; i++) {
	scanf("%d %d %d", &a, &b, &c);
	cards[i] = {a, b, c};
    }
    int rst = 1;
    vector<int> dp(n, 1);
    sort(cards.begin(), cards.end());
    for (int i = 1; i < n; i++) {
	for (int j = 0; j < i; j++) {
	    if (helper(cards[j], cards[i])) {
		dp[i] = max(dp[i], dp[j] + 1);
		rst = max(rst, dp[i]);
	    }
	}
    }

    cout << rst << endl;

    return 0;
}
