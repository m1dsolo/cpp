#include <iostream>

using namespace std;

const int N = 20;

int arr[N][N] = 0;
int n, i1, j1, i2, j2;

int main() {
    scanf("%d", &n);
    int rst1 = 0, rst2 = 0;
    if (n != 1) {
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		scanf("%d", &arr[i][j]);
		if (arr[i][j] == -1) {
		    i1 = i;
		    j1 = j;
		}
		else if (arr[i][j] == -2) {
		    i2 = i;
		    j2 = j;
		}
	    }
	}
	int val = 0;
	if (n == 2) {
	    if (i1 == i2) {
		if (i1) {
		    val = arr[0][0] + arr[0][1];
		    rst1 = val - arr[0][0], rst2 = val - arr[0][1];
		}
		else {
		    val = arr[1][0] + arr[1][1];
		    rst1 = val - arr[1][0], rst2 = val - arr[1][1];
		}
		if (j1) swap(rst1, rst2);
	    }
	    else if (j1 == j2) {
		if (j1) {
		    val = arr[0][0] + arr[1][0];
		    rst1 = val - arr[0][0], rst2 = val - arr[1][0];
		}
		else {
		    val = arr[0][1] + arr[1][1];
		    rst1 = val - arr[0][1], rst2 = val - arr[1][1];
		}
		if (i1) swap(rst1, rst2);
	    }
	    else {
		if (i1 && j1 || i2 && j2) {
		    val = arr[0][0] + arr[1][1];
		    rst1 = val - arr[1][1], rst2 = val - arr[0][0];
		}
		else {
		    val = arr[0][1] + arr[1][0];
		    rst1 = val - arr[1][0], rst2 = val - arr[0][1];
		}
		if (i1) swap(rst1, rst2);
	    }
	}
	else {
	    for (int i = 0; i < n; i++) {
		if (i1 == i || i2 == i) continue;
		for (int j = 0; j < n; j++)
		    val += arr[i][j];
		break;
	    }

	}
    }

    return 0;
}
