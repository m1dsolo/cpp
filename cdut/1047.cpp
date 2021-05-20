#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int arr[6];
    for (int i = 0; i < 6; i++)
	scanf("%d", &arr[i]);

    cout << pow(arr[0] + arr[1] + arr[2], 2) - pow(arr[0], 2) - pow(arr[2], 2) - pow(arr[4], 2) << endl;


    return 0;
}
