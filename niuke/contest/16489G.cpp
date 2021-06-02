#include <iostream>

using namespace std;
using ll = long long;

int arr[20], op[20];

int map[] = {0, 1, 2, 1, 1, 4, 2, 2, 2, 4, 2, 4, 1, 4, 4, 4, 
        4, 2, 2, 3, 1, 2, 1, 1, 2, 4, 1, 4, 3, 1, 3, 
        3, 4, 3, 2, 3, 3, 1, 4, 4, 2, 1, 1, 2, 2, 4, 4, 2, 4, 4, 4, 3, 
        2, 3, 3, 1, 4, 4, 3, 4, 1, 4, 2, 4};


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);
    for (int i = 0; i < n - 1; i++)
	scanf("%d", &op[i + 1]);
    
    ll rst = arr[0];
    for (int i = 1; i < n; i++) {
	switch (map[op[i]]) {
	    case 1: rst += arr[i]; break;
	    case 2: rst -= arr[i]; break;
	    case 3: rst *= arr[i]; break;
	    case 4: rst /= arr[i]; break;
	}
    }

    printf("%lld\n", rst);

    return 0;
}

