#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n, a;
    scanf("%d", &n);
    bitset<200010> s;
    s[100000] = 1;
    for (int i = 0; i < n; i++) {
	scanf("%d", &a);
	s = s | (s << a) | (s >> a); 
    }

    int rst = 0;
    for (int i = 100001; i <= 200000; i++)
	rst += s[i];

    printf("%d\n", rst);

    return 0;
}
