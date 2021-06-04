// https://blog.csdn.net/GD_ONE/article/details/104660294
#include <iostream>
#include <vector>

using namespace std;

// 比O(n)大一点
// 120 = pow(2, 3) * 3 * 5(120被2， 3， 5都筛过了)
void e_sieve(int n) {
    vector<bool> v(n + 1, true);
    v[1] = false;
    for (int i = 2; i < n; i++) {
	if (v[i]) {
	    cout << i << endl;
	    for (int j = i * i; j < n; j += i)	// i * i是因为：5 * 2已经被2 * 5筛过了，只需要从5 * 5开始筛就行
		v[j] = false;
	}
    }
}

// 欧拉筛核心思想就是确保每个合数只被最小的质因数或者说是最大的因子筛掉(最小质因数*最大因子 == 那个数？)
const int N = 100;
bool visited[N];
int primes[N], cnt;
void euler_sieve() {
    for (int i = 2; i < N; i++) {
	if (!visited[i])
	    primes[cnt++] = i;
	for (int j = 0; primes[j] * i < N; j++) {   // j < cnt没必要
	    visited[primes[j] * i] = true;
	    if (!(i % primes[j]))	// break防止12被4筛掉，让6筛
		break;
	}
    }
}

int main() {
    euler_sieve();

    for (int i = 0; i < cnt; i++)
	cout << primes[i] << " ";
    cout << endl;

    return 0; 
}
