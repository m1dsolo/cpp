#include <iostream>

using namespace std;

const int N = 510;

int arr[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++)
	    scanf("%d", &arr[i][j]);
    }




    return 0;
}
