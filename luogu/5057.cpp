#include <iostream>

using namespace std;

int arr[(int)1e5 + 10];

#define lowbit(x) ((x) & (-x))

int n;
void update(int i) {
    for (; i <= n; i += lowbit(i))
	arr[i] ^= 1;
}

int query(int i) {
    int rst = 0;
    for (; i; i -= lowbit(i))
	rst ^= arr[i];
    return rst;
}

int main() {
    int m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
	scanf("%d %d", &a, &b);
	if (a == 1) {
	    scanf("%d", &c);
	    update(b);
	    update(c + 1);
	}
	else
	    cout << query(b) << endl;
    }

    return 0;
}
