#include <iostream>

using namespace std;


//int joseph_ring(int n, int k) {
    //int rst = 0;
    //for (int i = 2; i <= n; i++)
	//rst = (rst + k) % i;
    //return rst + 1;
//}

int joseph_ring(int n, int k) {
    int rst = 0;
    for (int i = 2; i <= n; i++) {
	int num = min((i - 1 - rst) / k, n - i);
	i += num;
	rst = (rst + k * (num + 1)) % i;
    }
    return rst + 1;
}
int main() {
    cout << joseph_ring(100000, 2) << endl;

    return 0;
}
