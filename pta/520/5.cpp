#include <iostream>

using namespace std;

const int N = 5e6 + 10;

unsigned long long sum[N];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (unsigned long long i = 1; i < N; i++)
	sum[i] = sum[i - 1] + i * i;	

    int ptr = n + 1;
    while (ptr < N / 2) {
	if (sum[ptr] - sum[ptr - n - 1] == sum[ptr + n] - sum[ptr])
	    break;
	ptr++;
    }

    cout << ptr - n << "^2";
    for (int i = ptr - n + 1; i <= ptr; i++)
	cout << " + " << i << "^2";
    cout << " =" << endl << ptr + 1 << "^2";
    for (int i = ptr + 2; i <= ptr + n; i++)
	cout << " + " << i << "^2";
    cout << endl;

    return 0;
}
