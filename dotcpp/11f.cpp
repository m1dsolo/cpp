#include <iostream>

using namespace std;

int *arr;
int main() {
    int n;
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    int pass = 0;
    int good = 0;
    for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
	if (arr[i] >= 60) pass++;
	if (arr[i] >= 85) good++;
    }

    printf("%.0lf%\n", (double)pass * 100 / n);
    printf("%.0lf%\n", (double)good * 100 / n);

    return 0;
}
