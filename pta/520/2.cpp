#include <iostream>

using namespace std;

int main() {
    int a, b, c, val;
    scanf("%d %d %d", &a, &b, &c);

    if ((val = a - b * c) <= (a / 2))
	printf("hai sheng %d mi! chong ya!\n", val);
    else
	printf("hai sheng %d mi! jia you ya!\n", val);

    return 0;
}
