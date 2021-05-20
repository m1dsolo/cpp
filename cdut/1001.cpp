#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e6 + 10;

int arr[N];

bool is_prime(int n) {
    if (n <= 3) return n > 1;
    if (n % 6 != 1 && n % 6 != 5) return false;

    int max_i = sqrt(n);
    for (int i = 5; i <= max_i; i += 6) {
	if (!(n % i) || !(n % (i + 2)))
	    return false;
    }

    return true;
}

int main() {
    int n, m, k, tmp, max_val = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
	scanf("%d", &arr[i]);
	max_val = max(max_val, arr[i]);
    }

    int rst = 0;
    if (max_val < k) {
	while (1) {
	    if (arr[m] >= k) break;
	    int index = ((tmp = (m + arr[m]) % n) ? tmp : n);
	    arr[index] += is_prime(arr[index]) ? arr[m] : 1;
	    m = index;
	    rst++;
	}
    }

    printf("%d\n", rst);

    return 0;
}
