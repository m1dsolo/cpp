#include <iostream>
#include <cmath>

using namespace std;

const int n = 10;
int st[n + 1], ed[n + 1], bel[n + 1];

int main() {
    int sq = sqrt(n);
    for (int i = 1; i <= sq; i++) {
	st[i] = n / sq * (i - 1) + 1;
	ed[i] = n / sq * i;
    }
    ed[sq] = n;

    for (int i = 1; i <= sq; i++) {
	for (int j = st[i]; j <= ed[i]; j++)
	    bel[j] = i;
    }

    for (int i = 1; i <= n; i++)
	cout << i << " " << bel[i] << endl;


    return 0;
}
