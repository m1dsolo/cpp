#include <iostream>

using namespace std;
using ll = long long;

ll f[21] = {1};

int main() {
    ll n;
    for (int i = 1; i <= 20; i++)
	f[i] = f[i - 1] * i;
    while (scanf("%lld", &n) != EOF) {
	int cnt = 0;
	ll rst = 1;
	for (int i = 2; i <= n / i; i++) {
	    int num = 0;
	    while (!(n % i)) {
		n /= i;
		num++;
	    }
	    rst *= f[num];
	    cnt += num;
	}
	if (n > 1) cnt++;
	printf("%d %lld\n", cnt, f[cnt] / rst);	    // 质因数个数，多重集排列数(n! / (n1! * n2!))
    }

    return 0;
}
