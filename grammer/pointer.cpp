#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
	printf("%d\n", arr + i);
    printf("%d\n", &arr + 1);
    printf("%d\n", *(&arr + 1) - 1);
    printf("%d\n", *(*(&arr + 1) - 1));

    return 0;
}
