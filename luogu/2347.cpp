#include <iostream>
#include <bitset>

using namespace std;

const int N = 1010;
int w[] = {1, 2, 3, 5, 10, 20};

bitset<N> s;
int main() {
    int a;
    s[0] = 1;
    for (int i = 0; i < 6; i++) {
	scanf("%d", &a);
	for (int j = 0; j < a; j++)
	    s |= s << w[i];
    }

    printf("Total=%d\n", s.count() - 1);

    return 0;
}
