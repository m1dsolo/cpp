#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 110;

int arr1[N], arr2[N];

int main() {
    int n, m;
    unordered_set<int> set;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d", &arr1[i]);
	set.insert(arr1[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
	scanf("%d", &arr2[i]);
	set.insert(arr2[i]);
    }

    bool finish = false;
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    int val = arr1[i] + arr2[i];
	    if (!set.count(val)) {
		printf("%d %d\n", arr1[i], arr2[i]);
		finish = true;
		break;
	    }
	}
	if (finish) break;
    }



    return 0;
}
